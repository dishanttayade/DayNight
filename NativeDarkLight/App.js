import React from 'react';
import {Switch} from 'react-native';
import styled from 'styled-components/native';
import ThemeManager, { useTheme } from './modes/ThemeManager';
 
const Container = styled.View`
  flex: 1;
  background:${props => props.theme.backgroundAlt};
  align-items: center;
  justify-content: center;`
 
const Title = styled.Text`
  font-size: 24;
  color: ${props => props.theme.text};
`   
 function HomeScreen() {
    const theme = useTheme()
    return (
      <Container>
        <Title>{theme.mode}</Title>
        <Switch
          value={theme.mode === 'dark'}
          onValueChange={value => theme.setMode(value ? 'dark' : 'light')}
        />
      </Container>
    )
  }
class App extends React.Component{
  
render(){
  return (
   <ThemeManager>
      <HomeScreen />
    </ThemeManager>
  );
}
};
 
export default App;