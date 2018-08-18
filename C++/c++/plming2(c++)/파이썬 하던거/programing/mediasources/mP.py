



def mP(pic):
  w=getWidth(pic)
  mirrorPoint=w/2
  for x in range(0,mirrorPoint):
    for y in range(0,getHeight(pic)):
      p=getPixel(pic,x,y)
      pTarget=getPixel(pic,w-x-1,y)
      color=getColor(p)
      setColor(pTarget,color)
  repaint(pic)
  return(pic)  
  