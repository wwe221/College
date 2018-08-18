#3_1 when the file is transformed to jpg, jpg files size is compressed.
def getBytesOfPic(pic):
  pic="c:/beach.jpg"
  p=makePicture(pic)
  w=getWidth(p)
  h=getHeight(p)
  nBytes=w*h*3
  print nBytes
def lab3_1():
  fn="c:/beach.jpg"
  pic=makePicture(fn)
  getBytesOfPic(pic)


#3_2
def clearRed(pic):
  for p in getPixels(pic):
    r=getRed(p)
    setRed(p,r*0)
  repaint(pic)
def clearGreen(pic):
  for p in getPixels(pic):
    g=getGreen(p)
    setGreen(p,g*0)
  repaint(pic)  
def clearBlue(pic):
  for p in getPixels(pic):
    b=getBlue(p)
    setBlue(p,b*0)
  repaint(pic)  
def lab3_2():
  pic=makePicture ("c:/beach.jpg")
  clearRed(pic)
  clearGreen(pic)
  clearBlue(pic)


#3_3
def maxRed(pic):
  for p in getPixels(pic):
    r=getRed(p)
    setRed(p,r+255)
  repaint(pic)
def maxGreen(pic):
  for p in getPixels(pic):
    g=getGreen(p)
    setGreen(p,g+255)
  repaint(pic) 
def maxBlue(pic):
  for p in getPixels(pic):
    b=getBlue(p)
    setBlue(p,b+255)
  repaint(pic)  
def lab3_3():
  pic=makePicture ("c:/beach.jpg")
  maxRed(pic)
  maxGreen(pic)
  maxBlue(pic)


#3_4
def changeColor(pic):
  for p in getPixels(pic):
    r=getRed(p)
    g=getGreen(p)
    b=getBlue(p)
    number1=r
    number2=g
    number3=b
    allchange=makeColor(r*amount, g*amount, b*amount)
    setColor(p, allchange)
  repaint(pic)   
def lab3_4():
  fn="c:/beach.jpg"
  pic=makePicture(fn)
  changeColor(pic)
  

def main():
  lab3_1()
  lab3_2()
  lab3_3()
  lab3_4()