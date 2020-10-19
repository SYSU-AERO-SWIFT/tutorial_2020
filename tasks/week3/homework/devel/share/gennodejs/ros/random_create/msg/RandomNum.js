// Auto-generated. Do not edit!

// (in-package random_create.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class RandomNum {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.randNum = null;
      this.callback = null;
    }
    else {
      if (initObj.hasOwnProperty('randNum')) {
        this.randNum = initObj.randNum
      }
      else {
        this.randNum = 0;
      }
      if (initObj.hasOwnProperty('callback')) {
        this.callback = initObj.callback
      }
      else {
        this.callback = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RandomNum
    // Serialize message field [randNum]
    bufferOffset = _serializer.uint8(obj.randNum, buffer, bufferOffset);
    // Serialize message field [callback]
    bufferOffset = _serializer.uint8(obj.callback, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RandomNum
    let len;
    let data = new RandomNum(null);
    // Deserialize message field [randNum]
    data.randNum = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [callback]
    data.callback = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a message object
    return 'random_create/RandomNum';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8a632e4b30aa8c63125730332e5ca6e8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 randNum
    uint8 callback
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RandomNum(null);
    if (msg.randNum !== undefined) {
      resolved.randNum = msg.randNum;
    }
    else {
      resolved.randNum = 0
    }

    if (msg.callback !== undefined) {
      resolved.callback = msg.callback;
    }
    else {
      resolved.callback = 0
    }

    return resolved;
    }
};

module.exports = RandomNum;
