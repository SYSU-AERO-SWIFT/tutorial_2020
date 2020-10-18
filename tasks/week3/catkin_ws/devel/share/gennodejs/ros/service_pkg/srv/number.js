// Auto-generated. Do not edit!

// (in-package service_pkg.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class numberRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.number = null;
    }
    else {
      if (initObj.hasOwnProperty('number')) {
        this.number = initObj.number
      }
      else {
        this.number = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type numberRequest
    // Serialize message field [number]
    bufferOffset = _serializer.float32(obj.number, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type numberRequest
    let len;
    let data = new numberRequest(null);
    // Deserialize message field [number]
    data.number = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'service_pkg/numberRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ded049c24c756963282afab14b2d0f6d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 number
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new numberRequest(null);
    if (msg.number !== undefined) {
      resolved.number = msg.number;
    }
    else {
      resolved.number = 0.0
    }

    return resolved;
    }
};

class numberResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.feedback = null;
    }
    else {
      if (initObj.hasOwnProperty('feedback')) {
        this.feedback = initObj.feedback
      }
      else {
        this.feedback = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type numberResponse
    // Serialize message field [feedback]
    bufferOffset = _serializer.bool(obj.feedback, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type numberResponse
    let len;
    let data = new numberResponse(null);
    // Deserialize message field [feedback]
    data.feedback = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'service_pkg/numberResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f1f168a39479bedb24dba7a087426182';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool feedback
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new numberResponse(null);
    if (msg.feedback !== undefined) {
      resolved.feedback = msg.feedback;
    }
    else {
      resolved.feedback = false
    }

    return resolved;
    }
};

module.exports = {
  Request: numberRequest,
  Response: numberResponse,
  md5sum() { return '856707387f0b62b7754ee4f39be9c0f3'; },
  datatype() { return 'service_pkg/number'; }
};
