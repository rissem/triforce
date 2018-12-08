console.log('hello world')

navigator.requestMIDIAccess().then(access => {
    const inputs = access.inputs.values()
    const outputs = access.outputs.values()
    const input = inputs.next()
    if (input.value) {
        input.value.onmidimessage = function(event) {
            const [msg, d1, d2] = event.data
            if (msg == 176 && d1 == 66 && d2 == 127) {
                playPause(event)
            }
            console.log('MIDI EVENT', event)
            fetch(`http://localhost:5000?msg=${msg}&d1=${d1}&d2=${d2}`, { mode: 'no-cors' })
        }
    }
})
