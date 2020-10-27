/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */

import React from 'react';
import {
  SafeAreaView,
  StyleSheet,
  ScrollView,
  View,
  Text,
  StatusBar,
} from 'react-native';

import {getDeviceNameSync} from 'react-native-device-info';

const App: () => React$Node = () => {
  return (
    <View style={styles.container}>
      <Text> Hallo </Text>
      <Text> {getDeviceNameSync()} </Text>
    </View>
  );
};

export default App;

const styles = StyleSheet.create({
  container: {
    paddingTop: 100,
  },
});
