def makeSunset(picture):  
  for p in getPixels(picture):
    value=getBlue(p)
    setBlue(p,value*0.9)
    value=getGreen(p)
    setGreen(p,value*0.9)
def slowsunset():
  canvas = makePicture ( getMediaPath ("beach.jpg"))
  for num in range(1,10):
    makeSunset(canvas)
    writePictureTo(canvas,getMediaPath()+'/mysunset%03d.jpg' % num)
  return getMediaPath()+'mysunset%03d.jpg' % 1
  aFrame = slowSunset()
  dirS = makeMovieFromInitialFile ( aFrame )
  playMovie ( dirS )