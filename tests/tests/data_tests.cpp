/*
 * Copyright (c) 2018 AAA Foundation., and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <boost/test/unit_test.hpp>

#include <graphene/chain/database.hpp>
#include <graphene/chain/exceptions.hpp>

#include <graphene/chain/account_object.hpp>
#include <graphene/chain/data_asset_object.hpp>

#include <fc/crypto/digest.hpp>

#include "../common/database_fixture.hpp"

using namespace graphene::chain;
using namespace graphene::chain::test;

BOOST_FIXTURE_TEST_SUITE( data_tests, database_fixture )

BOOST_AUTO_TEST_CASE( create_data_asset )
{
   try {
      BOOST_TEST_MESSAGE("Attempting to create data asset object");
      string url("url-to-ipfs");
      string test_data("hello world");
      string test_desc("this is a test data");
      BOOST_TEST_MESSAGE( "start create data asset" );
      data_asset_id_type test_data_asset_id = db.get_index<data_asset_object>().get_next_id();
      data_asset_create_operation creator;
      creator.owner = account_id_type();
      creator.fee = asset();
      creator.url = url;
      //creator.data_hash = fc::sha256::hash(test_data);
      creator.data_hash = 0;
      creator.data_size = test_data.length();
      creator.data_desc = test_desc;
      //verify the data_key later
      creator.data_key = 0;

      trx.operations.push_back(std::move(creator));
      PUSH_TX( db, trx, ~0 );

      BOOST_TEST_MESSAGE("try to load the newly create object from db");
      const data_asset_object& test_data_asset = test_data_asset_id(db);
      BOOST_CHECK(test_data_asset.url == url);
      BOOST_CHECK(test_data_asset.data_size == test_data.length());
      BOOST_CHECK(test_data_asset.data_desc == test_desc);

   } catch(fc::exception& e) {
      edump((e.to_detail_string()));
      throw;
   }
}

BOOST_AUTO_TEST_SUITE_END()
