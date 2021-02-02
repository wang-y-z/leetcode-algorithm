# 深度学习编译器-编译优化-高性能计算

## 导语

> 1. 深度学习编译器作为一个新兴研究方向，属于sys for ml方向，属于系统软件方向。本质目标是以减少人工繁重冗杂的部署工作，通过软件定义的自动化解放生产力；实现**高性能、通用性和易用性**；
> 2. 相关系统研究方向关键词：<u>深度学习编译器、机器学习系统、分布式系统、深度学习推理框架、深度学习端侧推理引擎、图编译器、高性能算子库、异构计算、异构编程框架、图神经网络框架、张量编译、SOSP、OSDI。</u>

> **学习计划：**
>
> 1. 广度搜索：罗列当前有关工作，对比特性；
> 2. 深度搜索：将上述关键特性进行对比：重点比较库、技术路线、核心技术难点、架构。

[toc]

## 学习资源

https://github.com/merrymercy/awesome-tensor-compilers

>  A list of awesome compiler projects and papers for tensor computation and deep learning. 

balabala...

## 开源深度学习编译器

### TVM

### [TC](https://www.zhihu.com/question/267167829)

### ONNC/onnxruntime

### [TF-XLA-TFRT](https://zhuanlan.zhihu.com/p/302566750)

### [MLIR-IREE](https://zhuanlan.zhihu.com/p/141256429)

### [oneflow](https://mp.weixin.qq.com/s?__biz=MzU5ODY2MTk3Nw==&mid=2247484382&idx=1&sn=ba1ddb13c7122a01bf1ce0751c5bfe8b&scene=21#wechat_redirect)

### [RAMMER/nnfusion](https://zhuanlan.zhihu.com/p/275837455)

### TASO

### TACO

### Tiramisu 

### nGraph/PlaidML

### Glow

### jittor

## 自动代码生成

### Ansor

### polyhedral

### OAID/AutoKernel

### Mindspore/akg

## 推理引擎

TensorRT

MNN

NCNN-->Rapidnet-->TNN

caffe2

旷视的MegEngine

OpenAILab的Tengine

SNPE（Qualcomm）

TF lite

MACE

 MACE

anakin-->paddle-lite

华为bolt【ARM CPU，ARM GPU，X86 CPU】

快手YCNN

序列推理引擎：[bytedance/lightseq](https://mp.weixin.qq.com/s?__biz=MzA3MzI4MjgzMw==&mid=2650800627&idx=2&sn=234b9b1126b0ff0aacaffe2c4584b676&scene=21#wechat_redirect)

## 高性能库

cudnn/cuda/cublas

MKL

openBLASW

Eigen

NNPACK

[QNNPACK-Facebook-量化神经网络加速库](https://zhuanlan.zhihu.com/p/81026071)

arm compute library

## 图像处理编译器

Halide

polymage

> Halide有手工调度和自动调度，PolyMage就是其自动调度的工具；有点类似TVM和TC

## 自研芯片编译器

平头哥/TVM

寒武纪c910

寒武纪BANGC语言和编译器

nvdla软件栈

[GraphCore/Popla](https://mp.weixin.qq.com/s?__biz=MjM5MTEyMzQyNw==&mid=2247486828&idx=1&sn=1889e3f4af75b3c42ec714cf24de3827&scene=21#wechat_redirect)r

[清华-尹首一-芯片和编译器](https://zhuanlan.zhihu.com/p/269070510?utm_source=wechat_session&utm_medium=social&utm_oi=549622257622921216)

西安交通大学(CAG)HIPU-HIDK

## 异构编程框架

OpenCL

OpenGL

Vulkan

Metal

## 图神经网络框架

Euler

## 训练框架

CXXnet

caffe

\------------------

MXNet

TF

caffe2

pytorch

MegEngine

CNTK

PaddlePaddle