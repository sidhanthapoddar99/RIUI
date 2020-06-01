
# coding: utf-8

# In[26]:


import speech_recognition as sr
 
# Record Audio
r = sr.Recognizer()
mic = sr.Microphone(device_index=0)


# In[27]:



sr.Microphone.list_microphone_names()


# In[52]:

def voice():
    with mic as source:
        r.adjust_for_ambient_noise(source)
        audio = r.listen(source)
    print("done")    
    speech_to_text = r.recognize_google(audio)
    return(speech_to_text)



def wait():
    p='c'
    while(p!='p'):
        f=open("sema.txt","r")
        p=f.read(1)
        f.close()





def signal():
    f=open("sema.txt","w")
    f.write("c")
    f.close()

while(1):
    wait()
    print("enter")
    f=open("s.txt","w")
    i=voice()
    print("exit")
    print(i)
    i=i.lower()
    f.write(str(i))
    f.close()
    signal() 



