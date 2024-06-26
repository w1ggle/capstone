
#https://blog.tensorflow.org/2018/04/speed-up-tensorflow-inference-on-gpus-tensorRT.html April 18, 2018
# https://developer.nvidia.com/blog/tensorrt-integration-speeds-tensorflow-inference/ 

GPUmem = 7000000000
tfGPUMem = .50
gpu_options = tf.GPUOptions(per_process_gpu_memory_fraction = tfGPUMem)

output_node_name = ['score_fr/biases', 'fc6/biases', 'fc6/weights', 'score_pool3/biases', 'upscore2/up_filter', 'upscore4/up_filter', 'fc7/biases', 'upscore32/up_filter', 'score_pool4/biases', 'fc7/weights', 'score_fr/weights', 'score_pool4/weights', 'score_pool3/weights', 'decoder/Softmax']
batch_size = 1
workspace_size = (1 - tfGPUMem) * GPUmem


trt_graph = trt.create_inference_graph(
                input_graph_def="model_v1_0.pb",
                outputs=output_node_name,
                max_batch_size=batch_size,
                max_workspace_size_bytes=workspace_size,
                precision_mode="FP16")


tf.io.write_graph(graph_or_graph_def=trt_graph.graph,
                      logdir="./frozen_models",
                      name="simple_frozen_graph.pb",
                      as_text=False)