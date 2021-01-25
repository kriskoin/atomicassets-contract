/*
 * @file
 * @author  (C) 2021 by thegnometech
 *
 * @section LICENSE

 * @section DESCRIPTION
 *  
 *
 */

const { Api, JsonRpc, RpcError } = require("eosjs");
const { JsSignatureProvider } = require("eosjs/dist/eosjs-jssig"); // development only
const fetch = require("node-fetch"); // node only; not needed in browsers
const { TextEncoder, TextDecoder } = require("util"); // node only; native TextEncoder/Decoder
const atomicassets_priv_key = "5Hvs3RNPW ... uDMvbxuMaZGvneit"; // the priv key for "EOS5GaN2Qd7u8KWkWuy1oXHGH52t8WghLLHrcgHmZd1nC5N8vEL2M"


const signatureProvider = new JsSignatureProvider([lifebank_priv_key]);
const rpc = new JsonRpc("http://localhost:8888", { fetch });
const api = new Api({
  rpc,
  signatureProvider,
  textDecoder: new TextDecoder(),
  textEncoder: new TextEncoder(),
});
const get = require("lodash.get");
var chai = require("chai"),
  assert = chai.assert;

describe("Atomic assets unit test", function () {
  it("Testing mint a asset", async () => {
    try {
      const result = await api.transact(
        {
          
        },
        {
          blocksBehind: 3,
          expireSeconds: 30,
        }
      );
    } catch (err) {
      assert.equal(err, "Error: minting an asset within the blockchain");
    }
  });

});
