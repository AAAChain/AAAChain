#include "chainbase.hpp"
#include "TestChainBase.h"


#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>

#include <iostream>

using namespace chainbase;
using namespace boost::multi_index;

struct book : public chainbase::object<0, book> {

   template<typename Constructor, typename Allocator>
    book(  Constructor&& c, Allocator&& a ) {
       c(*this);
    }

    id_type id;
    int a = 0;
    int b = 1;
};

typedef multi_index_container<
  book,
  indexed_by<
     ordered_unique< member<book,book::id_type,&book::id> >,
     ordered_non_unique< BOOST_MULTI_INDEX_MEMBER(book,int,a) >,
     ordered_non_unique< BOOST_MULTI_INDEX_MEMBER(book,int,b) >
  >,
  chainbase::allocator<book>
> book_index;

CHAINBASE_SET_INDEX_TYPE( book, book_index )


ChainBaseTest::ChainBaseTest()
{
}

void ChainBaseTest::SetUp(){
   temp = boost::filesystem::unique_path();
   try {
      std::cerr << temp.native() << " \n";
      pDb = new  chainbase::database(temp, database::read_write, 1024*1024*8);
      pDb->add_index<book_index>();
   } catch ( ... ) {
      bfs::remove_all( temp );
      throw;
   }
}

void ChainBaseTest::TearDown(){
      bfs::remove_all( temp );
      delete pDb;
}

TEST_F(ChainBaseTest, createObject) {
      chainbase::database& db = *pDb;
      const auto& bk = db.create<book>( []( book& b ) {
          b.a = 3;
          b.b = 4;
      } );

     const auto& bk1 = db.get(book::id_type(0));
 
     EXPECT_EQ(bk.a, bk1.a);
     EXPECT_EQ(bk.b, bk1.b);
}

TEST_F(ChainBaseTest, modifyObject) {
      chainbase::database& db = *pDb;
      const auto& bk = db.create<book>( []( book& b ) {
          b.a = 3;
          b.b = 4;
      } );

      db.modify( bk, [&]( book& b ) {
          b.a = 5;
          b.b = 6;
      });

     EXPECT_EQ(bk.a, 5);
     EXPECT_EQ(bk.b, 6);
}

