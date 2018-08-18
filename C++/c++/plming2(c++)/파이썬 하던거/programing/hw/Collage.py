pic1=makePicture(getMediaPath('waterfall1.jpg'))
pic2=makePicture(getMediaPath('waterfall1.jpg'))
pic3=makePicture(getMediaPath('waterfall1.jpg'))
pic4=makePicture(getMediaPath('waterfall1.jpg'))
canvas=makePicture(getMediaPath('7inX95in.jpg'))

def main():
  mirror(pic1)
  mirrorFail(pic2)
  color1(pic3)
  color2(pic4)
  collage()
def mirror(pic1):
  mp=getHeight(pic1)/2
  height=getHeight(pic1)
  for x in range(0,getWidth(pic1)):
    for y in range(0,mp):
      tP=getPixel(pic1,x,y)
      bP=getPixel(pic1,x,height-y-1)
      color=getColor(tP)
      setColor(bP,color)
  writePictureTo(pic1,"F:/programing/img/p1.jpg")
  repaint(pic1)

def mirrorFail(pic2):
  mp1=getWidth(pic2)/2
  width=getWidth(pic2)
  for x in range(0,mp1):
    for y in range(0,getHeight(pic2)):
      tP=getPixel(pic2,width-mp1-1,y)
      bP=getPixel(pic2,x,y)
      color=getColor(tP)
      setColor(bP,color)
  writePictureTo(pic2,"F:/programing/img/p2.jpg")
  repaint(pic2)

def color1(pic3):
  for p in getPixels(pic):
    r = getRed(p)
    g = getGreen(p)
    b = getBlue(p)
    luminance = (r+g+b)/3
    if luminance < 64:
      setColor(p,black)
    if luminance >= 64:
      setColor(p,white)
  writePictureTo(pic3,"F:/programing/img/p3.jpg")
  repaint(pic3)
  
def color2(pic4):
  for x in getPixels(pic4):
    blackOrWhite=(getRed(x)+getGreen(x)+getBlue(x))/3
    setColor(x,makeColor(blackOrWhite,blackOrWhite,blackOrWhite))
  writePictureTo(pic4,"F:/programing/img/p4.jpg")
  repaint(pic4)
  

def copyGnerrally(source,target,targX,targY):
  targetX=targX
  for sourceX in range(0,getWidth(pic1)):
    targetY=targY
    for sourceY in range(0,getHeight(pic1)):
      px=getPixel(source,sourceX,sourceY)
      tx=getPixel(target,targetX,targetY)
      setColor(tx,getColor(px))
      targetY=targetY + 1
    targetX=targetX + 1
      
def collage():
  a=makePicture(getMediaPath("p1.jpg"))
  b=makePicture(getMediaPath("p2.jpg"))
  c=makePicture(getMediaPath("p3.jpg"))
  d=makePicture(getMediaPath("p4.jpg"))
  canvas=makePicture(getMediaPath("7inX95in.jpg"))
  copyGnerrally(a,canvas,0,0)
  copyGnerrally(b,canvas,getWidth(canvas)/2,0)
  copyGnerrally(c,canvas,0,getHeight(canvas)/2)
  copyGnerrally(d,canvas,getWidth(canvas)/2,getHeight(canvas)/2)
  writePictureTo(canvas,"F:/programing/img/Collage!!.jpg")
  explore(canvas)
  return canvas