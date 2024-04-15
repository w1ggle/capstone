# https://blog.tensorflow.org/2019/06/high-performance-inference-with-TensorRT.html

import tensorflow.contrib.tensorrt as trt


converted _graph_def = trt.create_inference_graph(
     input_graph_def = frozen_graph,
     outputs=[‘logits’, ‘classes’])