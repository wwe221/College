news1=makePicture(getMediaPath('1.jpg'))
news2=makePicture(getMediaPath('2.jpg'))
news3=makePicture(getMediaPath('3.jpg'))
news4=makePicture(getMediaPath('4.jpg'))
news5=makePicture(getMediaPath('5.jpg'))

def sw():
 newsmake(news1,'Son and Kim are two top',1)
 newsmake(news2,'Power of the Nationalteam',30)
 newsmake(news3,'Expactation of Volleyball team',60)
 newsmake(news4,'Kim got call of duty ',90)
 newsmake(news5,'Team have problem',120)
 aFrame=getMediaPath()+'/news/frame001.jpg'
 amovie=makeMovieFromInitialFile(aFrame)
 playMovie(amovie)
 
def newsmake(news,text,d):
 for x in range (d,d+29):
  c=news
  style=makeStyle(sansSerif,bold,24)
  addRectFilled(c,0,15,540,36,white)
  addTextWithStyle (c,x*3,38,text,style)
  writePictureTo(c,getMediaPath()+'/news/frame%03d.jpg'%x)
  
  
  

  
 
 
