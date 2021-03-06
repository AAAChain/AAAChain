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
#pragma once
#include <graphene/chain/protocol/data_asset.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <graphene/db/generic_index.hpp>

namespace graphene { namespace chain {
   class account_object;
   class database;
   using namespace graphene::db;

   /**
    *  @brief tracks the parameters of an data asset
    *  @ingroup object
    *
    */
   class data_asset_object : public graphene::db::abstract_object<data_asset_object>
   {
      public:
         static const uint8_t space_id = protocol_ids;
         static const uint8_t type_id  = data_asset_object_type;

         /// The url for the data asset content, i.e. "http://12.0.0.1:8080/ipfs/$hash""
	 /// notice the content of data asset is stored on seperated data chain.
         string url;

	 /// The hash value of the data asset content
	 int data_hash;

	 /// Size of data asset content, in byte
	 int data_size;
	
	 /// Descriton of the data
	 string data_desc;

	 /// Owner who created the data asset
	 account_id_type ownerId;

	 /// the buyer of the data asset
	 optional<account_id_type> buyer;

	 /// The encrypted private key for data
	 int data_key; //need to double check the data type?

         data_asset_id_type get_id()const { return id; }

	 /// the data owner can update data encryption key
	 void updateDataKey(int current_key); 

         void validate()const
         {
         }

   };

   struct by_owner;
   typedef multi_index_container<
      data_asset_object,
      indexed_by<
         ordered_unique< tag<by_id>, member< object, object_id_type, &object::id > >,
         ordered_non_unique< tag<by_owner>, member<data_asset_object, account_id_type, &data_asset_object::ownerId > >
      >
   > data_asset_object_multi_index_type;
   typedef generic_index<data_asset_object, data_asset_object_multi_index_type> data_asset_index;

} } // graphene::chain

FC_REFLECT_DERIVED( graphene::chain::data_asset_object, (graphene::db::object),
                    (url)
                    (data_hash)
                    (data_size)
                    (data_desc)
                    (ownerId)
                    (buyer)
                    (data_key)
                  )
