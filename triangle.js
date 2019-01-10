const heldNotes = {}
let pedalNotes = {}
let pedal = false

const noteDown = note => {
  heldNotes[note] = 1
  if (pedal) {
    pedalNotes[note] = 1
  }

  console.log('SUSTAINED NOTES', sustainedNotes())
  fetch(
    'http://localhost:5000?triangle=true&notes=' + Object.keys(sustainedNotes()).join('_'),
    {}
  ).then(res => {
    res.text().then(text => {
      document.getElementById('chord').innerHTML = text.replace(/([A-Z])-/g, function(x, y) {
        console.log(arguments)
        return y + 'b'
      })
    })
  })
}

const noteUp = note => {
  delete heldNotes[note]
  if (sustainedNotes.length == 0) return
  // fetch('http://localhost:5000?notes=' + Object.keys(sustainedNotes()).join('_'), {}).then(res => {
  //   res.text().then(text => {
  //     document.getElementById('chord').innerHTML = text
  //   })
  // })
}

const pedalDown = () => {
  pedal = true
  Object.assign(pedalNotes, heldNotes)
}

const pedalUp = () => {
  pedal = false
  pedalNotes = {}
}

const sustainedNotes = () => {
  const sustainedNotes = {}
  Object.assign(sustainedNotes, pedalNotes)
  Object.assign(sustainedNotes, heldNotes)
  return sustainedNotes
}

navigator.requestMIDIAccess().then(access => {
  const inputs = access.inputs.values()
  const outputs = access.outputs.values()
  const input = inputs.next()
  if (input.value) {
    input.value.onmidimessage = function(event) {
      const [msg, d1, d2] = event.data
      console.debug(msg, d1, d2)
      if (msg == 144) {
        noteDown(d1)
      }
      if (msg == 128) {
        noteUp(d1)
      }
      if (msg == 176 && d2 == 127) {
        pedalDown()
      }
      if (msg == 176 && d2 == 0) {
        pedalUp()
      }
    }
  }
})
