#pragma once

#include <memory>
#include <string>
#include <vector>

#include "proto/cnn.pb.h"

#include "cnn/network.hpp"

namespace cnn
{

template<typename Dtype>
class Optimizer
{
 public:
    explicit Optimizer(const OptimizerProto& _proto);
    explicit Optimizer(const std::string& filename);
    void init(const OptimizerProto& _proto);

    void start_training();

    void register_data_callback(void (*f)(const std::vector<Array<Dtype>*> &))
    {
        network_->register_data_callback(f);
    }
 private:
    void update_parameters(int current_iter);
 private:
    void print_parameters();

 private:
    OptimizerProto proto_;

    std::shared_ptr<Network<Dtype>> network_;
};

}  // namespace cnn

#include "../../src/optimizer.cpp"
