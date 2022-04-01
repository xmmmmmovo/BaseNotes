import React, { useState } from 'react'

let nextId = 0

export default function List() {
  const [name, setName] = useState('')
  const [artists, setArtists] = useState<
    {
      id: number
      name: string
    }[]
  >([])

  return (
    <>
      <h1>Inspiring sculptors:</h1>
      <input value={name} onChange={e => setName(e.target.value)} />
      <button
        onClick={() => {
          if (name === '') return
          setName('')
          setArtists([...artists, { id: nextId++, name: name }])
        }}
      >
        Add
      </button>
      <ul>
        {artists.map(artist => (
          <li key={artist.id}>{artist.name}</li>
        ))}
      </ul>
    </>
  )
}
