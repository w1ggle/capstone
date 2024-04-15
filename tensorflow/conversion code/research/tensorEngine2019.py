# https://stackoverflow.com/questions/57315179/how-to-save-tensorrt-graph-generated-from-frozen-inference-graph
import tensorflow as tf
from tensorflow.python.compiler.tensorrt import trt_convert as trt

with tf.Session() as sess:
    # First deserialize your frozen graph:
    with tf.gfile.GFile('frozen_inference_graph.pb', 'rb') as f:
        frozen_graph = tf.GraphDef()
        frozen_graph.ParseFromString(f.read())
    # Now you can create a TensorRT inference graph from your
    # frozen graph:
    converter = trt.TrtGraphConverter(
        input_graph_def=frozen_graph,
        nodes_blacklist=['outputs/Softmax']) #output nodes
    trt_graph = converter.convert()
    # Import the TensorRT graph into a new graph and run:
    output_node = tf.import_graph_def(
        trt_graph,
        return_elements=['outputs/Softmax'])
    sess.run(output_node)
    
    saved_model_dir_trt = "./tensorrt_model.trt"
    converter.save(saved_model_dir_trt)
    
    
    
    class avm_ss: # semantic segmentation for avm image    
    def __init__(self, filepath):
        self.graph = self.load_pb(filepath)
        self.output = self.graph.get_tensor_by_name('decoder/Softmax:0')
        self.input = self.graph.get_tensor_by_name('Placeholder:0')    
        self.sess = tf.compat.v1.Session(graph=self.graph)

        hypes_filepath = './models/hypes.json'
        with open(hypes_filepath, 'r') as f:
            self.hypes = json.load(f)        

        self.color_seg={1:(0,153,255,127), 2:(0,255,0,127), 3:(255,0,0,127), 4:(255,0,255,127)}
                
        self.num_classes = self.hypes['num_classes']
        self.threshold=[]
        for c in range(self.num_classes):
            threshold_name = 'threshold_{:d}'.format(c)
            threshold = np.array(self.hypes['threshold'][threshold_name])
            self.threshold.append(threshold)
        
        print('[avm_ss] model graphs are built')
    
    def load_pb(self, pb):
        with tf.io.gfile.GFile(pb, "rb") as f:
            graph_def = tf.compat.v1.GraphDef()
            graph_def.ParseFromString(f.read())
        with tf.Graph().as_default() as graph:
            tf.import_graph_def(graph_def, name='')
            
        return graph  