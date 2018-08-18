def blendPictures():
  barb=makePicture(getMediaPath("barbara.jpg"))
  katie=makePicture(getMediaPath("katie-smaller.jpg"))
  canvas=makePicture(getMediaPath("640x480.jpg"))
  sourceX=0
  for targetX in range(0,50):
    sourceY=0
    for targetY in range(0,getHeight(barb)):
      color=getColor(getPixel(barb,sourceX,sourceY))
      setColor(getPixel(canvas,targetX,targetY),color)
      sourceY=sourceY+1
  sourceX=sourceX+1
  overlap=getWidth(barb)-50
  sourceX=0
  for targetX in range(50,getWidth(barb)):
    sourceY=0
    for targetY in range(0,getHeight(katie)):
      bPixel=getPixel(barb,sourceX+50,sourceY)
      kPixel=getPixel(katie,sourceX,sourceY)
      newRed=0.75*getRed(bPixel)+0.25*getRed(kPixel)
      newGreen=0.75*getGreen(bPixel)+0.25*getGreen(kPixel)
      newBlue=0.75*getBlue(bPixel)+0.25*getBlue(kPixel)
      color=makeColor(newRed,newGreen,newBlue)
      setColor(getPixel(canvas,targetX,targetY),color)
      sourceY=sourceY+1
    sourceX=sourceX+1
  sourceX=overlap
  for targetX in range(150+overlap,100+getWidth(katie)):
    sourceY=0
    for targetY in range(0,getHeight(katie)):
      color=getColor(getPixel(katie,sourceX,sourceY))
      setColor(getPixel(canvas,targetX,targetY),color)
      sourceY=sourceY+1
    sourceX=sourceX+1
  show(canvas)
  return canvas
