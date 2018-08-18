def lab8_2():
  echo()
  sawtooth()
  DJ()

def echo():
  s1=makeSound(getMediaPath('preamble.wav'))
  s2=makeSound(getMediaPath('preamble.wav'))
  explore(s1)
  delay=15000
  for i in range(2*delay+1, getLength(s1)):
    echo1 = 0.6*getSampleValueAt(s2, i-delay)
    echo2 = 0.6*getSampleValueAt(s2, i-delay*2)
    combo = getSampleValueAt(s1, i) + echo1+echo2
    setSampleValueAt(s1, i, combo)
  explore(s1)
  play(s1)

#8.10
def sawtooth():
  freq=12 
  amplitude=20000
  mySound = getMediaPath("sec1silence.wav")
  square = makeSound(mySound)
  samplingRate = getSamplingRate(square)
  seconds = 1
  interval = 1.0 * seconds / freq
  samplesPerCycle = interval * samplingRate
  samplesPerHalfCycle = int(samplesPerCycle / 2)
  sampleVal = amplitude
  s  = 1
  i = 1
  for s in range (0, getLength(square)):
    if (i > samplesPerHalfCycle):
      sampleVal = sampleVal * -1
      i = 0
    setSampleValueAt(square,s,sampleVal)
    i = i + 1
  explore(square)
  return(square)

#8.14 
def DJ():
  source=makeSound(getMediaPath('preamble.wav'))
  play(source)
  reverse()
  faster()

def reverse():
  sound=makeSound(getMediaPath('preamble.wav'))
  explore(sound)
  target=makeEmptySound(getLength(sound))
  Index=getLength(sound)-1
  for i in range(0,getLength(sound)):
    s=getSampleValueAt(sound,Index)
    setSampleValueAt(target,i,s)
    Index=Index-1
  play(target)

def faster():
  sound=makeSound(getMediaPath('preamble.wav'))
  explore(sound)
  len=getLength(sound)/2+1
  target=makeEmptySound(len)
  targetIndex=0
  for soundIndex in range(0,getLength(sound),2):
    soundValue=getSampleValueAt(sound,soundIndex)
    setSampleValueAt(target,targetIndex,soundValue)
    targetIndex=targetIndex+1
  play(target)
  return target
  
  
  
  
  