
#pragma once

#include <vector>

#include "cnn/layer.hpp"

namespace cnn
{
/**
 * One input bottom[0] with shape (N, C, H, W)
 * and one output top[0] with shape (N, num_output, H, W)
 *
 */
template<typename Dtype>
class ConvolutionLayer : public Layer<Dtype>
{
 public:
    explicit ConvolutionLayer(const LayerProto&);

    void reshape(
            const std::vector<const Array<Dtype>*>& bottom,
            const std::vector<Array<Dtype>*>& bottom_gradient,
            const std::vector<Array<Dtype>*>& top,
            const std::vector<Array<Dtype>*>& top_gradient) override;

    void fprop(
            const std::vector<const Array<Dtype>*>& bottom,
            const std::vector<Array<Dtype>*>& top) override;

    void bprop(
            const std::vector<const Array<Dtype>*>& bottom,
            const std::vector<Array<Dtype>*>& bottom_gradient,
            const std::vector<const Array<Dtype>*>& top,
            const std::vector<const Array<Dtype>*>& top_gradient) override;
 private:
    int num_output_;
    int kernel_size_;
};


}  // namespace cnn

#include "../../src/convolution_layer.cpp"

