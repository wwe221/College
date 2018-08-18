s1=makeSound(getMediaPath("airplane.wav"))
def faster(s):
  sound=s
  explore(sound)
  len=getLength(sound)/2+1
  target=makeEmptySound(len)
  targetIndex=0
  for soundIndex in range(0,getLength(sound),2):
    soundValue=getSampleValueAt(sound,soundIndex)
    setSampleValueAt(target,targetIndex,soundValue)
    targetIndex=targetIndex+1
  play (target)
  return target