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

      string             url;
      int                data_hash;
      int                data_size;
      string             data_desc; 
      account_id_type    ownerId;
      int                data_key;

      authority       owner;
      authority       active;

      account_id_type   fee_payer()const { return ownerId; }
      void              validate()const;
   };

   struct data_asset_update_operation : public base_operation
   {

      struct ext
      {
         optional< void_t >            null_ext;
         optional< special_authority > owner_special_authority;
         optional< special_authority > active_special_authority;
      };

      struct fee_parameters_type { uint64_t fee = 0*GRAPHENE_BLOCKCHAIN_PRECISION; };
      asset              fee;

      account_id_type   ownerId;

      authority       owner;
      authority       active;
      extension< ext > extensions;

      account_id_type   fee_payer()const { return ownerId; }
      void              validate()const;
      share_type      calculate_fee(const fee_parameters_type& k)const;
      void get_required_active_authorities( flat_set<account_id_type>& a )const
      { a.insert( ownerId ); }
   }; 

} } // graphene::chain

FC_REFLECT( graphene::chain::data_asset_create_operation::fee_parameters_type, (fee) )
FC_REFLECT( graphene::chain::data_asset_create_operation,
            (url)
            (data_hash)
            (data_size)
            (data_desc)
            (ownerId)
            (data_key)
          )
FC_REFLECT( graphene::chain::data_asset_update_operation::fee_parameters_type, (fee) )
FC_REFLECT( graphene::chain::data_asset_update_operation,
            (ownerId)
          )
