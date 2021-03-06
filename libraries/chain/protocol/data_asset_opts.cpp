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
#include <graphene/chain/protocol/data_asset.hpp>

namespace graphene { namespace chain {

void data_asset_create_operation::validate() const
{
   FC_ASSERT(data_size > 0);
}

share_type data_asset_create_operation::calculate_fee( const fee_parameters_type& schedule )const
{
    ilog("data asset update operation:calculate_fee");
    share_type core_fee_required = schedule.fee;
    return core_fee_required;
}

void data_asset_update_operation::validate() const
{
    ilog("data_asset_update_operation::validate ..");
}

share_type data_asset_update_operation::calculate_fee( const fee_parameters_type& schedule )const
{
   ilog("data asset update operation:calculate_fee");
   share_type core_fee_required = schedule.fee;
   return core_fee_required;
}

} }
