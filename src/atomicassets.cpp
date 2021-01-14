#include <atomicassets.hpp>


/**
*  Initializes the config table. Only needs to be called once when first deploying the contract
*  @required_auth The contract itself
*/
ACTION atomicassets::init() {
    print("hi");
}

/**
*  Adds one or more lines to the format that is used for collection data serialization
*  @required_auth The contract itself
*/
ACTION atomicassets::admincoledit(vector <atomicdata::FORMAT> collection_format_extension) {
  print("hi");
}


/**
*  Sets the version for the tokenconfigs table
*  @required_auth The contract itself
*/
ACTION atomicassets::setversion(string new_version) {
   print("hi");
}


/**
*  Adds a token that can then be backed to assets
*  @required_auth The contract itself
*/
ACTION atomicassets::addconftoken(name token_contract, symbol token_symbol) {
   print("hi");
}


/**
*  Transfers one or more assets to another account
*  @required_auth The from account
*/
ACTION atomicassets::transfer(
    name from,
    name to,
    vector <uint64_t> asset_ids,
    string memo
) {
  print("hi");
}


/**
*  Creates a new collection
*/
ACTION atomicassets::createcol(
    name author,
    name collection_name,
    bool allow_notify,
    vector <name> authorized_accounts,
    vector <name> notify_accounts,
    double market_fee,
    ATTRIBUTE_MAP data
) {
    
print("hi");
   
}


/**
*  Sets the collection data, which is then serialized with the collection format set in the config
*  This data is used by 3rd party apps and sites to display additional information about the collection
*  @required_auth The collection author
*/
ACTION atomicassets::setcoldata(
    name collection_name,
    ATTRIBUTE_MAP data
) {
    print("hi");
}


/**
*  Adds an account to the authorized_accounts list of a collection
*  This will allow the account to create and edit both templates and assets that belong to this collection
*  @required_atuh The collection author
*/
ACTION atomicassets::addcolauth(
    name collection_name,
    name account_to_add
) {
   print("hi");
}


/**
*  Removes an account from the authorized_accounts list of a collection
*  @required_auth The collection author
*/
ACTION atomicassets::remcolauth(
    name collection_name,
    name account_to_remove
) {
    print("hi");
}


/**
*  Adds an account to the notify_accounts list of a collection
*  This will make the account get notified on every relevant action concerning this collection using require_recipient()
*  NOTE: It will consequently allow the account to make any of these actions throw (fail).
*        Only add trusted accounts to this list
*  @required_atuh The collection author
*/
ACTION atomicassets::addnotifyacc(
    name collection_name,
    name account_to_add
) {
    print("hi");
}


/**
*  Removes an account from the notify_accounts list of a collection
*  @required_auth The collection author
*/
ACTION atomicassets::remnotifyacc(
    name collection_name,
    name account_to_remove
) {
  print("hi");
}


/**
* Sets (changes) the market fee for an existing collection
* @required_auth The collection author
*/
ACTION atomicassets::setmarketfee(
    name collection_name,
    double market_fee
) {
    print("hi");
}


/**
* Sets allow_notify to false for a collection where it has previously been true
* The collection's notify_accounts list must be empty
* @required_auth The collection author
*/
ACTION atomicassets::forbidnotify(
    name collection_name
) {
   print("hi");
}


/**
*  Creates a new schema
*  schemas can only be extended in the future, but never changed retroactively.
*  This guarantees a correct deserialization for existing templates and assets.
*  @required_auth authorized_creator, who is within the authorized_accounts list of the collection
*/
ACTION atomicassets::createschema(
    name authorized_creator,
    name collection_name,
    name schema_name,
    vector <FORMAT> schema_format
) {
    print("hi");
}


/**
*  Adds one or more lines to the format of an existing schema
*  @required_auth authorized_editor, who is within the authorized_accounts list of the collection
*/
ACTION atomicassets::extendschema(
    name authorized_editor,
    name collection_name,
    name schema_name,
    vector <FORMAT> schema_format_extension
) {
    print("hi");
}


/**
*  Creates a new template
*  @required_auth authorized_creator, who is within the authorized_accounts list of the collection
*/
ACTION atomicassets::createtempl(
    name authorized_creator,
    name collection_name,
    name schema_name,
    bool transferable,
    bool burnable,
    uint32_t max_supply,
    ATTRIBUTE_MAP immutable_data
) {
    print("hi");
}


/**
* Sets the max supply of the template to the issued supply
* This means that afterwards no new assets of this template can be minted
* @required_auth authorized_editor, who is within the authorized_accounts list of the collection
**/
ACTION atomicassets::locktemplate(
    name authorized_editor,
    name collection_name,
    int32_t template_id
) {
    print("hi");
}


/**
*  Creates a new asset
*  Doesn't work if the template has a specified max_supply that has already been reached
*  @required_auth authorized_minter, who is within the authorized_accounts list of the collection
                  specified in the related template
*/
ACTION atomicassets::mintasset(
    name authorized_minter,
    name collection_name,
    name schema_name,
    int32_t template_id,
    name new_asset_owner,
    ATTRIBUTE_MAP immutable_data,
    ATTRIBUTE_MAP mutable_data,
    vector <asset> tokens_to_back
) {
 print("hi");
}


/**
*  Updates the mutable data of an asset
*  @required_auth authorized_editor, who is within the authorized_accounts list of the collection
                  specified in the related template
*/
ACTION atomicassets::setassetdata(
    name authorized_editor,
    name asset_owner,
    uint64_t asset_id,
    ATTRIBUTE_MAP new_mutable_data
) {
   
    print("hi");
}


/**
* This action is used to add a zero value asset to the quantities vector of owner in the balances table
* If no row exists for owner, a new one is created
* This action needs to be called before transferring (depositing) any tokens to the AtomicAssets smart contract,
* in order to pay for the RAM that otherwise would have to be paid by the AtomicAssets smart contract
*
* To pass a symbol to eosio as a string, use the following format: <precision>,<symbol_code>
* So for example: "8,WAX"
*
* @required_auth owner
*/
ACTION atomicassets::announcedepo(
    name owner,
    symbol symbol_to_announce
) {

    print("hi");
}


/**
* Withdraws fungible tokens that were previously deposited
*
* @required_auth owner
*/
ACTION atomicassets::withdraw(
    name owner,
    asset token_to_withdraw
) {
    print("hi");
}


/**
* Backs an asset with a fungible token that was previously deposited by payer
* payer also pays for the full RAM of the asset that is backed
* 
* @required_auth payer
*/
ACTION atomicassets::backasset(
    name payer,
    name asset_owner,
    uint64_t asset_id,
    asset token_to_back
) {
    print("hi");
}
    


/**
*  Burns (deletes) an asset
*  Only works if the "burnable" bool in the related template is true
*  If the asset has been backed with tokens previously, they are sent to the owner of the asset
*  @required_auth asset_owner
*/
ACTION atomicassets::burnasset(
    name asset_owner,
    uint64_t asset_id
) {
    print("hi");
}


/**
*  Creates an offer
*  Offers are two sided, with the only requirement being that at least one asset is included in one of the sides
*  @required_auth sender
*/
ACTION atomicassets::createoffer(
    name sender,
    name recipient,
    vector <uint64_t> sender_asset_ids,
    vector <uint64_t> recipient_asset_ids,
    string memo
) {
  print("hi");
}


/**
*  Cancels (deletes) an existing offer
*  @required_auth The offer's creator
*/
ACTION atomicassets::canceloffer(
    uint64_t offer_id
) {
  print("hi");
}


/**
*  Accepts an offer
*  The items specified in the offer from either side are transferred to the corresponding other side
*  If a new scope needs to be created, each side of the offer will pay for their own scope
*  @require_auth The offer's recipient
*/
ACTION atomicassets::acceptoffer(
    uint64_t offer_id
) {
    print("hi");
}


/**
*  Declines an offer
*  The offer is then erased from the tables
*  @require_auth The offer's recipient
*/
ACTION atomicassets::declineoffer(
    uint64_t offer_id
) {
    print("hi");
}


/**
* Pays for the RAM of an existing offer (thus freeing the RAM of the previous payer)
* The main purpose for this is to allow dapps to pay for the RAM of offer that their users create
* in order to make sure that the users don't run out of RAM
* @require_auth payer
*/
ACTION atomicassets::payofferram(
    name payer,
    uint64_t offer_id
) {
   print("hi");
}


/**
*  This function is called when a transfer receipt from any token contract is sent to the atomicassets contract
*  It handels deposits and adds the transferred tokens to the sender's balance table row
*/
void atomicassets::receive_token_transfer(name from, name to, asset quantity, string memo) {
    print("hi");
}


ACTION atomicassets::logtransfer(
    name collection_name,
    name from,
    name to,
    vector <uint64_t> asset_ids,
    string memo
) {
  print("hi");  
}


ACTION atomicassets::lognewoffer(
    uint64_t offer_id,
    name sender,
    name recipient,
    vector <uint64_t> sender_asset_ids,
    vector <uint64_t> recipient_asset_ids,
    string memo
) {
   print("hi");
}


ACTION atomicassets::lognewtempl(
    int32_t template_id,
    name authorized_creator,
    name collection_name,
    name schema_name,
    bool transferable,
    bool burnable,
    uint32_t max_supply,
    ATTRIBUTE_MAP immutable_data
) {
    print("hi");
}


ACTION atomicassets::logmint(
    uint64_t asset_id,
    name authorized_minter,
    name collection_name,
    name schema_name,
    int32_t template_id,
    name new_asset_owner,
    ATTRIBUTE_MAP immutable_data,
    ATTRIBUTE_MAP mutable_data,
    vector <asset> backed_tokens,
    ATTRIBUTE_MAP immutable_template_data
) {
    print("hi");
}


ACTION atomicassets::logsetdata(
    name asset_owner,
    uint64_t asset_id,
    ATTRIBUTE_MAP old_data,
    ATTRIBUTE_MAP new_data
) {
   print("hi");
}


ACTION atomicassets::logbackasset(
    name asset_owner,
    uint64_t asset_id,
    asset backed_token
) {
    print("hi");
}


ACTION atomicassets::logburnasset(
    name asset_owner,
    uint64_t asset_id,
    name collection_name,
    name schema_name,
    int32_t template_id,
    vector <asset> backed_tokens,
    ATTRIBUTE_MAP old_immutable_data,
    ATTRIBUTE_MAP old_mutable_data,
    name asset_ram_payer
) {
   print("hi");
}


/**
*  Transfers need to be handled like this (as a function instead of an action), because when accepting an offer,
*  we want each side of the offer to pay for their own scope. Because the recipient authorized the accept action,
*  he can be charged the RAM for his own scope, and because the offer is removed from the table, which was previously
*  paid by the offer sender, the action RAM delta for the sender account will still be positive even after paying
*  for the scope. This is allowed by the protocol feature RAM_RESTRICTIONS which needs to be enabled on the blockchain
*  that this contract is deployed on.
*/
void atomicassets::internal_transfer(
    name from,
    name to,
    vector <uint64_t> asset_ids,
    string memo,
    name scope_payer
) {
   print("hi");
}


/**
*  The specified asset is backed by the specified quantitiy.
*  This is done in an internal function because it is needed both in the mintasset and the backasset action
*/
void atomicassets::internal_back_asset(
    name payer,
    name asset_owner,
    uint64_t asset_id,
    asset token_to_back
) {
   print("hi");
}


/**
*  Decreases the balance of a specified account by a specified quantity
*  If the specified account does not have at least as much tokens in the balance as should be removed
*  the transaction will fail
*/
void atomicassets::internal_decrease_balance(
    name owner,
    asset quantity
) {
   print("hi");
}


/**
* Notifies all of a collection's notify accounts using require_recipient
*/
void atomicassets::notify_collection_accounts(
    name collection_name
) {
   print("hi");
}


/**
* Checks if the account_to_check is in the authorized_accounts vector of the specified collection
*/
void atomicassets::check_has_collection_auth(
    name account_to_check,
    name collection_name,
    string error_message
) {
   print("hi");
}


/**
* The "name" attribute is limited to 64 characters max for both assets and collections
* This function checks that, if there exists an ATTRIBUTE with name: "name", the value of it
* must be of length <= 64
*/
void atomicassets::check_name_length(
    ATTRIBUTE_MAP data
) {
    print("hi");
}


atomicassets::assets_t atomicassets::get_assets(name acc) {
    return assets_t(get_self(), acc.value);
}


atomicassets::schemas_t atomicassets::get_schemas(name collection_name) {
    return schemas_t(get_self(), collection_name.value);
}


atomicassets::templates_t atomicassets::get_templates(name collection_name) {
    return templates_t(get_self(), collection_name.value);
}