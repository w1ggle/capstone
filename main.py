#import everything
#import cameraStitching as cs
#import sementic_segmentation as ss
#import arduinoControl as ac
#import motionPlanning as mp 

PARKED = False #set false so we stay in while loop

#load model (which will open tf session) i think as long as we dont end code, session is still in play
#model_path = './models/trt_frozen_graphtf2FP32.pb'
#model = sementic_segmentation.avm_ss(model_path)

#wait for keyboard press, allows us to disconnect monitor and put the car on ground
input("disconnect car, place on ground, press enter when ready")

while PARKED is not True:
    # put AVM stitching code here *(make it into a file that can be imported)
    #surround = cs.runBEV() #AVM stitched and cropped output
    
    #run the model on on the avm output
    #labeledSurround = model.run(surround)
    
    #can uncommment this movement (will wiggle steering) to test if session stays active after mulitple wile loop iterations
    #ac.finish()
    
    #run the movement commands
    # PARKED = mp.movement(labeledSurround) #move forward, back left right etc. return true if parked at right spot
    print("continuing navigation")

#call finished function here. Will wiggle wheels for visual confirmation (wont have monitor unplugged so cant see terminal if done)
#ac.finish()
print("done!")