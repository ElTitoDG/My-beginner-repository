import React from 'react'
import Logo from './robinhood.svg';

function Header() {
  return (
    <div className="header__wrapper">
      {/* logo  */}
      <div className="header__logo">
        <img src={Logo} width={25}/>
      </div>
      {/* search */}
      <div className="header__search">
        <div className="header__searchContainer">
          <input placeholder="Search" type="text"/>
        </div>
      </div>
      {/*  menuitems */}
      <div className="header__menu">

      </div>
    </div>
  )
}

export default Header
