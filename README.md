# The "Black Pink Box" Project
My first Arduino project to controlling 10-channel Relay using MIDI in this case I used Ableton Live 9.

# Background 
Last month I got a challenge to make stunning light/visual show with low budget that can sync with music and visual. The Goal is to controlling lighting such as incandescent bulb, or xmas light (fairy lit) using some MIDI software such as Ableton Live 9, FL Studio or other DAW. After surf the internet, I've found that dis thing can simply be done with just using DMX, but it's so expensive. So I used cheap clone $6 Arduino UNO to solve dis prob.

# Hardware needed
- Arduino UNO
- 8+2 Channel Relay (https://bl.app.link/T9K1deSIsQ)
- 10 Contra Steker (https://kabelnym.com/shop/brand-series/broco-series/kontra-steker-hitam-broco-334n/)
- Wires
- Windows Laptop

# Software needed
- Digital Audio Workstation (I recomend Ableton Live 9) (https://www.ableton.com/en/trial/)
> Used for drawing lighting sequence, playing music and video

- Basic knowledge of using DAW (https://www.youtube.com/watch?v=1QPQoZGAA88)

- Hariless MIDI<->Serial Bridge (http://projectgus.github.com/hairless-midiserial)
> Used for converting MIDI Signal (come from Ableton) into Serial Signal (going to Arduino UNO)

- loopMIDI (https://www.tobias-erichsen.de/software/loopmidi.html)
> Act as MIDI Interface, so you can select it as Interface on Ableton

- MatroskaSplitter (http://www.free-codecs.com/download/matroska_splitter.htm)
> I don't really know, but you'll needed it to play a video 

- Quicktime Player 
> Needed to play video, Ableton will ask to install this program.

- Arduino Software (IDE) (https://www.arduino.cc/en/Main/Software)
> For uploading script into Arduino

# Schema
<img src="https://raw.githubusercontent.com/elybin/Black-Pink-Box/master/process%20diagram%20The%20Black%20Pink%20Box%20(1).jpg">

## 1. DAW (Ableon or FL Studio) [Inside Your Laptop]
First, our DAW playing the note sequence `(C-2 = Bulb 1, C#-2 = Bulb 2, ... A-2 = Bulb 10)` sending output as MIDI into `loopMidi Adapter`

## 2. loopMIDI [Inside Your Laptop]
Then, loopMIDI will continue the signal into the `Hariless MIDI<->Serial Bridge`, make sure `loopMIDI` switched on.

## 3. Hariless MIDI<->Serial Bridge [Inside Your Laptop]
Here where the magic happen, this app will convert your `MIDI Signal` into `Serial Signal`, so your Arduino UNO could understand what light should turned on/off.

## 4. Wires
`Laptop`   |USB Type-A Male)-----------------------------(USB Type-B Male|    `Arduino UNO`
 
## 5. Arduino UNO [Outside Laptop]
After receive Serial Signal, then `Arduino UNO` will running a program to send voltage to digital pin and trigger the `5V Relay`

# How to Use 
1. Install `Ableton`, `loopMIDI`, `Hariless MIDI<->Serial Bridge`, `MatroskaSplitter`,  `Quicktime Player`, `Arduino Driver` on your laptop
2. Load the Ableton Project file nammed `lighting_test.als` 
3. Setup your Ableton adapter, goto `Options`->`Preferences`->`MIDI Tab` then select output into `loopMIDI`
4. Open and start `loopMidi`, make sure there is data received
5. Connect your `Arduino` and upload the `Ableton_Arduino_Relay.ino` form `file_arduino` folder into your Arduino. Maybe you'll need `Arduino IDE` in this process.
6. Open `Hariless MIDI<->Serial Bridge` and select `Serial Port` into your `Arduino UNO`, select `MIDI In` into `loopMidi`. Also make sure the green dots blinking
7. If you follow the step correctly, you'll hearing the `Relay` starting to clicking, good luck!
