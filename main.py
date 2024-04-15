#import everything
#import cameraStitching as cs
#import sementic_segmentation as ss
#import arduinoControl as ac
#import motionPlanning as mp 

finished = False
PARKED = True #get variable from mp and remove this when ready

#load model (which will open tf session)
#model_path = './models/trt_frozen_graphtf2FP32.pb'
#model = sementic_segmentation.avm_ss(model_path)

#wait for keyboard press, allows us to disconnect monitor and put the car on ground
input("disconnect car, place on ground, press enter when ready")

while finished is not True:
    # put AVM stitching code here *(make it into a file that can be imported)
    #surround = cs.runBEV() #AVM stitched and cropped output
    
    #run the model on on the avm output
    #labeledSurround = model.run(surround)
    
    if PARKED is True:
        #call finished function here. Will wiggle wheels for visual confirmation (will have monitor unplugged so cant see terminal if done)
        #finished = ac.finish()
        finished = True
    else:
        #run the movement commands
        # PARKED = mp.movement(labeledSurround) #move forward, back left right etc. return true if parked at right spot
        print("continuing navigation")
    
print("done!")