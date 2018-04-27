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
#include <graphene/chain/protocol/asset_ops.hpp>
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
	 fc::uint128 content_hash;

	 /// Size of data asset content, in byte
	 int data_size;
	
	 /// Descriton of the data
	 string data_desc;

	 /// Owner who created the data asset
	 account_id_type owner;

	 /// the buyer of the data asset
	 optional<account_id_type> buyer;

	 /// The encrypted private key for data
	 public_key_type data_key; //need to double check the data type?

         data_asset_id_type get_id()const { return id; }

	 /// the data owner can update data encryption key
	 void updateDataKey(public_key_type current_key); 

         void validate()const
         {
         }

   };

} } // graphene::chain

FC_REFLECT_DERIVED( graphene::chain::data_asset_object, (graphene::db::object),
                    (url)
                    (content_hash)
                    (data_size)
                    (data_desc)
                    (owner)
                    (buyer)
                    (data_key)
                  )
