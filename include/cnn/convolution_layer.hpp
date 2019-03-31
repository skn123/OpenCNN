/*  ---------------------------------------------------------------------
  Copyright 2018-2019 Fangjun Kuang
  email: csukuangfj at gmail dot com
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a COPYING file of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>
  -----------------------------------------------------------------  */

#pragma once

#include <vector>

#include "cnn/layer.hpp"

namespace cnn {
/**
 * One input bottom[0] with shape (N, C, H, W)
 * and one output top[0] with shape (N, num_output, H, W)
 *
 */
template <typename Dtype>
class ConvolutionLayer : public Layer<Dtype> {
 public:
  explicit ConvolutionLayer(const LayerProto&);

  void reshape(const std::vector<const Array<Dtype>*>& bottom,
               const std::vector<Array<Dtype>*>& bottom_gradient,
               const std::vector<Array<Dtype>*>& top,
               const std::vector<Array<Dtype>*>& top_gradient) override;

  void fprop(const std::vector<const Array<Dtype>*>& bottom,
             const std::vector<Array<Dtype>*>& top) override;

  void bprop(const std::vector<const Array<Dtype>*>& bottom,
             const std::vector<Array<Dtype>*>& bottom_gradient,
             const std::vector<const Array<Dtype>*>& top,
             const std::vector<const Array<Dtype>*>& top_gradient) override;

 private:
  void one_channel_convolution(const Dtype* weight, const Dtype* src,
                               int height, int width, Dtype* dst);

  void one_channel_bprop(const Dtype* weight, const Dtype* bottom, int height,
                         int width, const Dtype* top_gradient,
                         Dtype* bottom_gradient, Dtype* param_gradient);

 private:
  int num_output_;
  int kernel_size_;
};

}  // namespace cnn

#include "../../src/convolution_layer.cpp"
