def repairTemple():
  temple=makePicture(getMediaPath('temple.jpg'))
  mPt=276
  for x in range(13,mPt):
    for y in range(27,97):
      p=getPixel(temple,x,y)
      c=getColor(p)
      pX=mPt+mPt-x-1
      pO=getPixel(temple,pX,y)
      setColor(pO,c)
  return temple
  