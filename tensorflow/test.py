import tensorrt as trt
import tensorflow as tf

print(tf.__version__)
print(trt.__version__)

pbPath = './models/model_v1_0.pb'

with tf.Session() as sess:
    with tf.io.gfile.GFile(pbPath, "rb") as f:
        graph_def = tf.compat.v1.GraphDef()
        graph_def.ParseFromString(f.read())
        
    converted_graph_def = trt.create_inference_graph(
        input_graph_def = graph_def,
        outputs=['decoder/Softmax'],
        precision_mode="FP16")
    
    tf.io.write_graph(graph_or_graph_def=converted_graph_def.graph_def,
                      logdir="./frozen_models",
                      name="trt_frozen_graph.pb",
                      as_text=False)