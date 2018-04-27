/*
 * Copyright (c) 2018 AAA Foundation and contributors.
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
#include <graphene/chain/data_asset_evaluator.hpp>
#include <graphene/chain/data_asset_object.hpp>
#include <graphene/chain/account_object.hpp>
#include <graphene/chain/database.hpp>
#include <graphene/chain/exceptions.hpp>

#include <functional>

namespace graphene { namespace chain {

void_result data_asset_create_evaluator::do_evaluate( const data_asset_create_operation& op )
{ try {


   FC_ASSERT(op.data_size > 0, "can't add empty data");
   return void_result();
} FC_CAPTURE_AND_RETHROW( (op) ) }

void data_asset_create_evaluator::pay_fee()
{
   //@todo: design and impl the pay related operation
   //generic_evaluator::pay_fee();
}

object_id_type data_asset_create_evaluator::do_apply( const data_asset_create_operation& op )
{ try {

   //auto next_data_asset_id = db().get_index_type<data_asset_index>().get_next_id();

   const data_asset_object& new_data_asset =
     db().create<data_asset_object>( [&]( data_asset_object& a ) {
         a.url = op.url;
         a.data_hash = op.data_hash;
	 a.data_size = op.data_size;
	 a.data_desc = op.data_desc;
	 a.owner = op.owner;
	 a.data_key = op.data_key;
      });
   //assert( new_data_asset.id == next_data_asset_id );

   return new_data_asset.id;
} FC_CAPTURE_AND_RETHROW( (op) ) }

} } // graphene::chain
