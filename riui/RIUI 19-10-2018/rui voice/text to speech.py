
# coding: utf-8

# In[2]:


import win32com.client as wi


# In[3]:


sp=wi.Dispatch("SAPI.SpVoice")


# In[23]:


def spe(st):
    
    sp.Speak(st)


# In[24]:


def wait():
    p='c'
    while(p!='p'):
        f=open("sema1.txt","r")
        p=f.read(1)
        f.close()



# In[25]:


def signal():
    f=open("sema1.txt","w")
    f.write("c")
    f.close()


# In[ ]:


while(1):
    wait()
    f=open("s.txt","r")
    p=f.readline()
    f.close()
    spe(p)
    signal()
    

