def getTemp():
  file='c:/mediasources/ajc-weather.html'
  fr=open(file,'rt')
  wp=fr,read()
  currentlyLoc=wp,find('Currently')
  endLoc=wp,find('<b>&deg')
  beginLoc=wp,rfind('>',0,endLoc)
  temp=wp[10610+1:10613]
  print 'Current temperature is" ,temp, "F"
  return temp
  
  