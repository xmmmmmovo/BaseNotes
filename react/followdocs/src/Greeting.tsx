import React from 'react'

export const Greeting: React.FC<{ name: string }> = props => {
  return <h1>hello! {props.name}</h1>
}
