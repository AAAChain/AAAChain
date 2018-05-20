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
#include <graphene/chain/protocol/base.hpp>
#include <graphene/chain/protocol/ext.hpp>
#include <graphene/chain/protocol/special_authority.hpp>

namespace graphene { namespace chain { 

   struct data_asset_create_operation : public base_operation
   {
 
      //set the fee to 0 during dev and test phase
      struct fee_parameters_type { uint64_t fee = 0*GRAPHENE_BLOCKCHAIN_PRECISION; };

      asset              fee;
      account_id_type    ownerId;
      string             url;
      string             data_desc; 
      int                data_hash;
      int                data_key;
      int                data_size;

      authority       owner;
      authority       active;

      account_id_type   fee_payer()const { return ownerId; }
      void              validate()const;
      share_type      calculate_fee(const fee_parameters_type& k)const;
   };

   struct data_asset_update_operation : public base_operation
   {

      struct fee_parameters_type { uint64_t fee = 0*GRAPHENE_BLOCKCHAIN_PRECISION; };
      asset              fee;

      account_id_type   ownerId;

      
      authority       owner;
      authority       active;

      account_id_type   fee_payer()const { return ownerId; }
      void              validate()const;
      share_type      calculate_fee(const fee_parameters_type& k)const;
   }; 

} } // graphene::chain

FC_REFLECT( graphene::chain::data_asset_create_operation::fee_parameters_type, (fee) )
FC_REFLECT( graphene::chain::data_asset_create_operation,
	    (fee)
            (ownerId)
            (url)
            (data_desc)
            (data_hash)
            (data_key) 
            (data_size)
	    (owner)(active)
          )
FC_REFLECT( graphene::chain::data_asset_update_operation::fee_parameters_type, (fee) )
FC_REFLECT( graphene::chain::data_asset_update_operation,
	    (fee)
            (ownerId)
	    (owner)(active)
          )
