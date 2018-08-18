def thankandyou():
  t=makeSound(getMediaPath('thank.wav'))
  a=makeSound(getMediaPath('and.wav'))
  s=makeSound(getMediaPath('sec3silence.wav'))
  y=makeSound(getMediaPath('you.wav'))
  tLen=getLength(t)
  aLen=getLength(a)
  sLen=getLength(s)
  yLen=getLength(y)
  silLen=int(0.1*getLength(s))
  sumLen=tLen+silLen+aLen+silLen+yLen
  target=makeEmptySound(sumLen)
  index=0
  for sample in range(0,tLen):
    v=getSampleValueAt(t,sample)
    setSampleValueAt(target,index,v)
    index=index+1
  for sample in range(0,silLen):
    setSampleValueAt(target,index,0)
    index=index+1
  for sample in range(0,aLen):
    vi=getSampleValueAt(a,sample)
    setSampleValueAt(target,index,vi)
    index=index+1
  for sample in range(0,silLen):
    setSampleValueAt(target,index,0)
    index=index+1
  for sample in range(0,yLen):
    vd=getSampleValueAt(y,sample)
    setSampleValueAt(target,index,vd)
    index=index+1
  play(target)
  explore(target)
  return target


def copySound(source, target, start):
  tIndex = start
  for sIndex in range(0, getLength(source)):
    value = getSampleValueAt(source, sIndex)
    setSampleValueAt(target,tIndex,value)
    tIndex = tIndex + 1

def normalize(sound):
  largest = 0
  for s in getSamples(sound):
    if abs(getSample(s)) > largest:
      largest = abs(getSample(s))

def musicword():
  music=makeSound(getMediaPath('ducks-thames.wav'))
  words=makeSound(getMediaPath('airplane.wav'))
  mLeng=getLength(music)
  wLeng=getLength(words)
  sumLen=makeEmptySound(mLeng+wLeng)
  index=0
  for sample in range(0,mLeng):
    v=getSampleValueAt(music,mLeng-1)
    setSampleValueAt(sumLen,index,v)
    index=index+1
  for sample in range(0,wLeng):
    v=getSampleValueAt(words,wLeng-1)
    setSampleValueAt(sumLen,index,v)
    index=index+1
  explore(music)
  return music

def erasesound():
  t=makeSound(getMediaPath("thisisatest.wav"))
  ss=int(getSamplingRate(t))
  index=0
  for source in range(ss,ss*2):
    value=getSampleValueAt(t,source)
    setSampleValueAt(t,index,0)
    index=index+1
  play(t)
  explore(t)
  return(t)

def main():
 thankandyou()
 musicword()
 erasesound()