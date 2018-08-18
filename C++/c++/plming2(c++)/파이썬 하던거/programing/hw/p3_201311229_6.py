w=makeSound(getMediaPath("around.wav"))
def main(s,v):
  lab6_1()
  lab6_2(s,v)


def lab6_1():
  
  c=0
  for sample in getSamples(w):
    v=getSampleValue(sample)
    if v == 0:
      c=c+1
  print c
  


def lab6_2(w):
  w=makeSound(getMediaPath("around.wav"))
  aa(w,2)
def aa(w,v):
  for sample in getSamples(w):
    sv=getSampleValue(sample)
    setSampleValue(sample,sv*v)
  play(w)
  return w
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       