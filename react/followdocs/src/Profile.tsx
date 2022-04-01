import React from 'react'

export const Profile: React.FC<{ name: string, imgId: string }> = props => {
  const imgUrl = 'https://i.imgur.com/' + props.imgId + 's.jpg'
  return <img className='avatar' src={imgUrl} alt={props.name} />
}
