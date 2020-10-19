// Auto-generated. Do not edit!

// (in-package publisher_pkg.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class myRandomRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.random_num = null;
    }
    else {
      if (initObj.hasOwnProperty('random_num')) {
        this.random_num = initObj.random_num
      }
      else {
        this.random_num = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type myRandomRequest
    // Serialize message field [random_num]
    bufferOffset = _serializer.float32(obj.random_num, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type myRandomRequest
    let len;
    let data = new myRandomRequest(null);
    // Deserialize message field [random_num]
    data.random_num = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'publisher_pkg/myRandomRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4176a749b1704bf728d01e1708640142';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 random_num
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new myRandomRequest(null);
    if (msg.random_num !== undefined) {
      resolved.random_num = msg.random_num;
    }
    else {
      resolved.random_num = 0.0
    }

    return resolved;
    }
};

class myRandomResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.judge = null;
    }
    else {
      if (initObj.hasOwnProperty('judge')) {
        this.judge = initObj.judge
      }
      else {
        this.judge = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type myRandomResponse
    // Serialize message field [judge]
    bufferOffset = _serializer.bool(obj.judge, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type myRandomResponse
    let len;
    let data = new myRandomResponse(null);
    // Deserialize message field [judge]
    data.judge = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'publisher_pkg/myRandomResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '39c17c8a5cd9af966a5aecabf6af7bef';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool judge
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new myRandomResponse(null);
    if (msg.judge !== undefined) {
      resolved.judge = msg.judge;
    }
    else {
      resolved.judge = false
    }

    return resolved;
    }
};

module.exports = {
  Request: myRandomRequest,
  Response: myRandomResponse,
  md5sum() { return 'af3f1147d7daae631b82b1a427cd4a2f'; },
  datatype() { return 'publisher_pkg/myRandom'; }
};
