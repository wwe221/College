#10.10
import os
def titleDirectory(dir):
  for file in os.listdir(dir):
    print "Processing:",dir+"//"+file
    picture = makePicture(dir+"//"+file)
    canvas = makePicture(getMediaPath("7inX95in.jpg"))    
    sourceX = 45
    for targetX in range(100,100+((200-45)/2)):
      sourceY = 25
      for targetY in range(100,100+((200-25)/2)):
        color = getColor(getPixel(picture,sourceX,sourceY))
        setColor(getPixel(canvas,targetX,targetY), color)
        sourceY = sourceY + 2
      sourceX = sourceX + 2
    show(picture)
    show(canvas)
    return canvas


#10.11
def secret(message):
  for numb in message:
    print ord(numb)+5
  print message
 
 
#10.17
def mirror(message):
  t=message
  t=t[::-1]
  mirror=message+t
  print(mirror)
    
    
#10.19    
def percentagegender(string):
  a=0
  b=0
  for g in string:
    if (g=="M"):
      a=a+1
    if (g=="W"):
      b=b+1
  Man=a*1.0/(a+b)
  Woman=b*1.0/(a+b)
  work=["There are"] + [Man] + ["males,"] + [Woman] + ["females."]
  print work[0],work[1],work[2],work[3],work[4]