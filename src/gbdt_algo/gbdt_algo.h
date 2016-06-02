/* Copyright 2016 Jiang Chen <criver@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Gradient Boosting Decision Tree (GBDT) Algorithms
// http://statweb.stanford.edu/~jhf/ftp/stobst.pdf

#ifndef GBDT_ALGO_H_
#define GBDT_ALGO_H_

#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

#include "src/base/base.h"

namespace gbdt {

class Config;
class DataStore;
class Forest;

// GBDT algorithnm
// Gradient Boosting Decision Tree (GBDT) Algorithm.
// The GBDT algorithm contains two configurable building blocks:
//
//  * LossFunc: Computes functional gradients and also has the option of changing example
//    weights.
//  * TreeFitter (FitTreeToGradients): Given the gradients and examples weights, build
//    a tree to minimize weighted mse of the gradients and weights.
//
// The generic framework allows us to implement a variety of algorithms by writing custom
// loss function.
// A General Boosting Method and its Application to Learning Ranking Functions for Web Search
// by Zheng et.al. describes an algorithm that uses Hessian to compute both weights and gradients.
//
// Inputs:
// * Config contains a collection of configurations including generate training params, loss
//   function, and tree building params.
// * DataStore is a container of data. It is not a const variable because some of our data
//   can be loaded in a lazy fashion.
unique_ptr<Forest> TrainGBDT(const Config& config, DataStore* data_store);


}  // namespace gbdt

#endif  // GBDT_ALGO_H_