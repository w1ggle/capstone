#import everything
#import arduinoControl as ac
#from motionPlanning import PARKED #get variable from parked spot
finished = False
PARKED = True #import above and remove this when ready

#load model (which will open tf session)
#model_path = './models/trt_frozen_graphtf2FP32.pb'
#ss = sementic_segmentation.avm_ss(model_path)

#wait for keyboard press, allows us to disconnect monitor and put the car on ground
input("disconnect car, place on ground, press enter when ready")

while finished is not True:
    # put AVM stitching code here *(make it into a file that can be imported)
    #surround = AVM stitched and cropped output
    
    #run the model on on the avm output
    #labeledSurround = ss.run(surround)
    
    if PARKED is True:
        #call finished function here. Will wiggle wheels and turn off motors to confirm
        #finished = ac.finish()
        finished = True
    else:
        #run the movement commands
        #move forward, back left right etc
        print("continuing navigation")
    
    
    
    
    
    
print("done!")