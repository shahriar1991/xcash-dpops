#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define_macro_functions.h"
#include "define_macros.h"
#include "structures.h"
#include "define_macros_test.h"

#include "string_functions.h"

#include "variables_test.h"
#include "string_functions_test.h"

/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: string_functions_test
Description: Test the string functions
Return: The number of passed string_functions test
-----------------------------------------------------------------------------------------------------------
*/

int string_functions_test(void)
{
  // define macros
  #define STRING_FUNCTIONS_TOTAL_TEST 9
  #define DATABASE_DATA 14
  #define MESSAGE "{\r\n \"message_settings_1\": \"XCASH_DPOPS_TEST_DATA_1\",\r\n \"message_settings_2\": \"XCASH_DPOPS_TEST_DATA_2\",\r\n}"
  #define CREATE_JSON_DATA_FROM_DATABASE_DOCUMENT_ARRAY_TEST_DATA "{\"username\":\"XCASH\",\"most_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_total_rounds\":\"5\",\"best_block_verifier_online_percentage_delegate_name\":\"DELEGATE_NAME\",\"best_block_verifier_online_percentage\":\"10\",\"most_block_producer_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_block_producer_total_rounds\":\"15\",\"most_VRF_node_public_and_private_key_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_VRF_node_public_and_private_key_total_rounds\":\"5\",\"most_VRF_node_random_data_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_VRF_node_random_data_total_rounds\":\"10\",\"total_XCASH_proof_of_stake_rounds\":\"15\",\"total_coins_in_proof_of_stake\":\"5\",\"total_circulating_supply_percentage_in_proof_of_stake\":\"10\"}"
  #define CREATE_JSON_DATA_FROM_DATABASE_MULTIPLE_DOCUMENTS_ARRAY_TEST_DATA "[{\"username\":\"XCASH\",\"most_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_total_rounds\":\"5\",\"best_block_verifier_online_percentage_delegate_name\":\"DELEGATE_NAME\",\"best_block_verifier_online_percentage\":\"10\",\"most_block_producer_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_block_producer_total_rounds\":\"15\",\"most_VRF_node_public_and_private_key_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_VRF_node_public_and_private_key_total_rounds\":\"5\",\"most_VRF_node_random_data_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_VRF_node_random_data_total_rounds\":\"10\",\"total_XCASH_proof_of_stake_rounds\":\"15\",\"total_coins_in_proof_of_stake\":\"5\",\"total_circulating_supply_percentage_in_proof_of_stake\":\"10\"},{\"username\":\"XCASH\",\"most_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_total_rounds\":\"5\",\"best_block_verifier_online_percentage_delegate_name\":\"DELEGATE_NAME\",\"best_block_verifier_online_percentage\":\"10\",\"most_block_producer_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_block_producer_total_rounds\":\"15\",\"most_VRF_node_public_and_private_key_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_VRF_node_public_and_private_key_total_rounds\":\"5\",\"most_VRF_node_random_data_total_rounds_delegate_name\":\"DELEGATE_NAME\",\"most_VRF_node_random_data_total_rounds\":\"10\",\"total_XCASH_proof_of_stake_rounds\":\"15\",\"total_coins_in_proof_of_stake\":\"5\",\"total_circulating_supply_percentage_in_proof_of_stake\":\"10\"}]"
  #define CREATE_JSON_DATA_FROM_DELEGATES_ARRAY_TEST_DATA "[{\"public_address\":\"XCA1h3yJ318hJGTFeXfYyEcyE7G4hX7jrCbvz21VecJGhf64Tw51yWii2Q1e76fJbB26Ea8CRipmdW6ZHQcRrLKx3cxRkr5M12\",\"total_vote_count\":\"0\",\"IP_address\":\"delegates.xcash.foundation\",\"delegate_name\":\"delegates_xcash_foundation\",\"about\":\"Official X-Network node\",\"website\":\"delegates.xcash.foundation\",\"team\":\"X-Network Team\",\"pool_mode\":\"false\",\"fee_structure\":\"0\",\"server_settings\":\"Operating System = Ubuntu 18.04 CPU = 32 threads (Intel 2xE5 - 2660 - 2.2GHz RAM = 256GB DDR3 Hard drive = 2x240 GB SSD + 4x2TB SATA Bandwidth Transfer = Unlimited Bandwidth Speed = 500 Mbps upload and 500 Mbps download\",\"block_verifier_score\":\"0\",\"online_status\":\"true\",\"block_verifier_total_rounds\":\"0\",\"block_verifier_online_total_rounds\":\"0\",\"block_verifier_online_percentage\":\"0\",\"block_producer_total_rounds\":\"0\",\"block_producer_block_heights\":\"0\"},{\"public_address\":\"XCA1kkdrRQ9SC7wfJ3F329giei31r13wKEKiD1ZMYf6nBiU8KE6a6LDJTZobfJ58o8A3vtGrAkzfHDd815kac7F17iPhK9zYGG\",\"total_vote_count\":\"0\",\"IP_address\":\"officialdelegate.xcash.foundation\",\"delegate_name\":\"officialdelegate_xcash_foundation\",\"about\":\"Official X-Network Shared Delegate\",\"website\":\"officialdelegate.xcash.foundation\",\"team\":\"X-Network Team\",\"pool_mode\":\"true\",\"fee_structure\":\"0\",\"server_settings\":\"Operating System = Ubuntu 18.04 CPU = 8 threads (Intel E3-1246 v3 - 3.50GHz RAM = 32GB DDR3 Hard drive = 2x HDD SATA 2 TB Bandwidth Transfer = Unlimited Bandwidth Speed = 1 Gbps upload and 1 Gbps download\",\"block_verifier_score\":\"0\",\"online_status\":\"true\",\"block_verifier_total_rounds\":\"0\",\"block_verifier_online_total_rounds\":\"0\",\"block_verifier_online_percentage\":\"0\",\"block_producer_total_rounds\":\"0\",\"block_producer_block_heights\":\"0\"}]"
  #define CREATE_JSON_DATA_FROM_VOTES_ARRAY_TEST_DATA "[{\"public_address_created_reserve_proof\":\"XCA1va68ZVYVDRzX3mpqVD8iWbxviCsUigMkyogxAWSQR5rk16g7dYjbcKDwsAggp8Z1dNjPgcCzkcV7hDg99Wtk8nyUBBK4K7\",\"public_address_voted_for\":\"XCA1va68ZVYVDRzX3mpqVD8iWbxviCsUigMkyogxAWSQR5rk16g7dYjbcKDwsAggp8Z1dNjPgcCzkcV7hDg99Wtk8nyUBBK4K7\",\"total\":\"0\",\"reserve_proof\":\"ReserveProofV11BZ23sBt9sZJeGccf84mzyAmNCP3KzYbE1111112VKmH111118PRh4AT7VvXjWBm8SAPTf55QJP1E3fkm8f3oe3VWeT5o8YybH9113USPdfBXLfpWTHYMCJAmGa2CcFiyHn5Gj9PCuHaKB3VHdqTEy6shyi4bW8FuTLyhTpDcnS7uEAyQcijSuHEUcgTwUSNSwuzvT113ka91zQXMcjYwZ39zAJVS16DuJZNRWnQaiNJVsracFDmUsXCCWcMx5HpKDNn5N3H1qSCxhV4CdUN2cB8Z2iirSgiL2frFA1DrVCKJm5kNHSANEGjHe4mw5L6L2Yeabna74FLszbBPKso42fpctQ8Djj25hqj6pEQqHY4tTaAYfkVRuB4m8DU4aNZN1Ak9vkBxvZtVDRzX3mpqVD8iWbxviCsUigMkyogxAWSQR5rjh4uUTRP7QHCpCm1o34Qc1vrDsLzXWbvcwC1g1VUh3S5dDKX2FXGJT4DX2REwtCNCZX2MZE2wGcbLRZ3vj4jQ6NzwTqT\"},{\"public_address_created_reserve_proof\":\"XCA1va68ZVYVDRzX3mpqVD8iWbxviCsUigMkyogxAWSQR5rk16g7dYjbcKDwsAggp8Z1dNjPgcCzkcV7hDg99Wtk8nyUBBK4K7\",\"public_address_voted_for\":\"XCA1va68ZVYVDRzX3mpqVD8iWbxviCsUigMkyogxAWSQR5rk16g7dYjbcKDwsAggp8Z1dNjPgcCzkcV7hDg99Wtk8nyUBBK4K7\",\"total\":\"0\",\"reserve_proof\":\"ReserveProofV11BZ23sBt9sZJeGccf84mzyAmNCP3KzYbE1111112VKmH111118PRh4AT7VvXjWBm8SAPTf55QJP1E3fkm8f3oe3VWeT5o8YybH9113USPdfBXLfpWTHYMCJAmGa2CcFiyHn5Gj9PCuHaKB3VHdqTEy6shyi4bW8FuTLyhTpDcnS7uEAyQcijSuHEUcgTwUSNSwuzvT113ka91zQXMcjYwZ39zAJVS16DuJZNRWnQaiNJVsracFDmUsXCCWcMx5HpKDNn5N3H1qSCxhV4CdUN2cB8Z2iirSgiL2frFA1DrVCKJm5kNHSANEGjHe4mw5L6L2Yeabna74FLszbBPKso42fpctQ8Djj25hqj6pEQqHY4tTaAYfkVRuB4m8DU4aNZN1Ak9vkBxvZtVDRzX3mpqVD8iWbxviCsUigMkyogxAWSQR5rjh4uUTRP7QHCpCm1o34Qc1vrDsLzXWbvcwC1g1VUh3S5dDKX2FXGJT4DX2REwtCNCZX2MZE2wGcbLRZ3vj4jQ6NzwTqT\"}]"

  // variables
  int count;
  int counter;
  struct database_document_fields database_data;
  struct database_multiple_documents_fields database_multiple_documents_fields;
  struct delegates delegates[MAXIMUM_AMOUNT_OF_DELEGATES];
  struct votes votes[MAXIMUM_AMOUNT_OF_DELEGATES];

  // reset the variables
  memset(result_test,0,sizeof(result_test));
  memset(data_test,0,sizeof(data_test));
  count_test = 0;

  // initialize the database_document_fields struct
  for (count = 0; count < DATABASE_DATA; count++)
  {
    database_data.item[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    database_data.value[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));

    if (database_data.item[count] == NULL || database_data.value[count] == NULL)
    {
      color_print("Could not allocate the memory needed on the heap","red");
      exit(0);
    }
  }

  memcpy(database_data.item[0],"username",8);
  memcpy(database_data.item[1],"most_total_rounds_delegate_name",31);
  memcpy(database_data.item[2],"most_total_rounds",17);
  memcpy(database_data.item[3],"best_block_verifier_online_percentage_delegate_name",51);
  memcpy(database_data.item[4],"best_block_verifier_online_percentage",37);
  memcpy(database_data.item[5],"most_block_producer_total_rounds_delegate_name",46);
  memcpy(database_data.item[6],"most_block_producer_total_rounds",32);
  memcpy(database_data.item[7],"most_VRF_node_public_and_private_key_total_rounds_delegate_name",63);
  memcpy(database_data.item[8],"most_VRF_node_public_and_private_key_total_rounds",49);
  memcpy(database_data.item[9],"most_VRF_node_random_data_total_rounds_delegate_name",52);
  memcpy(database_data.item[10],"most_VRF_node_random_data_total_rounds",38);
  memcpy(database_data.item[11],"total_XCASH_proof_of_stake_rounds",33);
  memcpy(database_data.item[12],"total_coins_in_proof_of_stake",29);
  memcpy(database_data.item[13],"total_circulating_supply_percentage_in_proof_of_stake",53);

  memcpy(database_data.value[0],"XCASH",5);  
  memcpy(database_data.value[1],"DELEGATE_NAME",13);
  memcpy(database_data.value[2],"5",1);
  memcpy(database_data.value[3],"DELEGATE_NAME",13);
  memcpy(database_data.value[4],"10",2);
  memcpy(database_data.value[5],"DELEGATE_NAME",13);  
  memcpy(database_data.value[6],"15",2);
  memcpy(database_data.value[7],"DELEGATE_NAME",13);  
  memcpy(database_data.value[8],"5",1);
  memcpy(database_data.value[9],"DELEGATE_NAME",13);  
  memcpy(database_data.value[10],"10",2);  
  memcpy(database_data.value[11],"15",2);
  memcpy(database_data.value[12],"5",1);
  memcpy(database_data.value[13],"10",2);

  database_data.count = DATABASE_DATA;

  // initialize the database_multiple_documents_fields struct 
  for (count = 0; count < 2; count++)
  {
    for (counter = 0; counter < DATABASE_DATA; counter++)
    {
      database_multiple_documents_fields.item[count][counter] = (char*)calloc(BUFFER_SIZE,sizeof(char));
      database_multiple_documents_fields.value[count][counter] = (char*)calloc(BUFFER_SIZE,sizeof(char));

      if (database_multiple_documents_fields.item[count][counter] == NULL || database_multiple_documents_fields.value[count][counter] == NULL)
      {
        color_print("Could not allocate the memory needed on the heap","red");
        exit(0);
      }
    }
  }

  memcpy(database_multiple_documents_fields.item[0][0],"username",8);
  memcpy(database_multiple_documents_fields.item[0][1],"most_total_rounds_delegate_name",31);
  memcpy(database_multiple_documents_fields.item[0][2],"most_total_rounds",17);
  memcpy(database_multiple_documents_fields.item[0][3],"best_block_verifier_online_percentage_delegate_name",51);
  memcpy(database_multiple_documents_fields.item[0][4],"best_block_verifier_online_percentage",37);
  memcpy(database_multiple_documents_fields.item[0][5],"most_block_producer_total_rounds_delegate_name",46);
  memcpy(database_multiple_documents_fields.item[0][6],"most_block_producer_total_rounds",32);
  memcpy(database_multiple_documents_fields.item[0][7],"most_VRF_node_public_and_private_key_total_rounds_delegate_name",63);
  memcpy(database_multiple_documents_fields.item[0][8],"most_VRF_node_public_and_private_key_total_rounds",49);
  memcpy(database_multiple_documents_fields.item[0][9],"most_VRF_node_random_data_total_rounds_delegate_name",52);
  memcpy(database_multiple_documents_fields.item[0][10],"most_VRF_node_random_data_total_rounds",38);
  memcpy(database_multiple_documents_fields.item[0][11],"total_XCASH_proof_of_stake_rounds",33);
  memcpy(database_multiple_documents_fields.item[0][12],"total_coins_in_proof_of_stake",29);
  memcpy(database_multiple_documents_fields.item[0][13],"total_circulating_supply_percentage_in_proof_of_stake",53);
  memcpy(database_multiple_documents_fields.item[1][0],"username",8);
  memcpy(database_multiple_documents_fields.item[1][1],"most_total_rounds_delegate_name",31);
  memcpy(database_multiple_documents_fields.item[1][2],"most_total_rounds",17);
  memcpy(database_multiple_documents_fields.item[1][3],"best_block_verifier_online_percentage_delegate_name",51);
  memcpy(database_multiple_documents_fields.item[1][4],"best_block_verifier_online_percentage",37);
  memcpy(database_multiple_documents_fields.item[1][5],"most_block_producer_total_rounds_delegate_name",46);
  memcpy(database_multiple_documents_fields.item[1][6],"most_block_producer_total_rounds",32);
  memcpy(database_multiple_documents_fields.item[1][7],"most_VRF_node_public_and_private_key_total_rounds_delegate_name",63);
  memcpy(database_multiple_documents_fields.item[1][8],"most_VRF_node_public_and_private_key_total_rounds",49);
  memcpy(database_multiple_documents_fields.item[1][9],"most_VRF_node_random_data_total_rounds_delegate_name",52);
  memcpy(database_multiple_documents_fields.item[1][10],"most_VRF_node_random_data_total_rounds",38);
  memcpy(database_multiple_documents_fields.item[1][11],"total_XCASH_proof_of_stake_rounds",33);
  memcpy(database_multiple_documents_fields.item[1][12],"total_coins_in_proof_of_stake",29);
  memcpy(database_multiple_documents_fields.item[1][13],"total_circulating_supply_percentage_in_proof_of_stake",53);

  memcpy(database_multiple_documents_fields.value[0][0],"XCASH",5);  
  memcpy(database_multiple_documents_fields.value[0][1],"DELEGATE_NAME",13);
  memcpy(database_multiple_documents_fields.value[0][2],"5",1);
  memcpy(database_multiple_documents_fields.value[0][3],"DELEGATE_NAME",13);
  memcpy(database_multiple_documents_fields.value[0][4],"10",2);
  memcpy(database_multiple_documents_fields.value[0][5],"DELEGATE_NAME",13);  
  memcpy(database_multiple_documents_fields.value[0][6],"15",2);
  memcpy(database_multiple_documents_fields.value[0][7],"DELEGATE_NAME",13);  
  memcpy(database_multiple_documents_fields.value[0][8],"5",1);
  memcpy(database_multiple_documents_fields.value[0][9],"DELEGATE_NAME",13);  
  memcpy(database_multiple_documents_fields.value[0][10],"10",2);  
  memcpy(database_multiple_documents_fields.value[0][11],"15",2);
  memcpy(database_multiple_documents_fields.value[0][12],"5",1);
  memcpy(database_multiple_documents_fields.value[0][13],"10",2);
  memcpy(database_multiple_documents_fields.value[1][0],"XCASH",5);  
  memcpy(database_multiple_documents_fields.value[1][1],"DELEGATE_NAME",13);
  memcpy(database_multiple_documents_fields.value[1][2],"5",1);
  memcpy(database_multiple_documents_fields.value[1][3],"DELEGATE_NAME",13);
  memcpy(database_multiple_documents_fields.value[1][4],"10",2);
  memcpy(database_multiple_documents_fields.value[1][5],"DELEGATE_NAME",13);  
  memcpy(database_multiple_documents_fields.value[1][6],"15",2);
  memcpy(database_multiple_documents_fields.value[1][7],"DELEGATE_NAME",13);  
  memcpy(database_multiple_documents_fields.value[1][8],"5",1);
  memcpy(database_multiple_documents_fields.value[1][9],"DELEGATE_NAME",13);  
  memcpy(database_multiple_documents_fields.value[1][10],"10",2);  
  memcpy(database_multiple_documents_fields.value[1][11],"15",2);
  memcpy(database_multiple_documents_fields.value[1][12],"5",1);
  memcpy(database_multiple_documents_fields.value[1][13],"10",2);

  database_multiple_documents_fields.document_count = 2;
  database_multiple_documents_fields.database_fields_count = DATABASE_DATA;

  // initialize the delegates struct 
  for (count = 0; (int)count < MAXIMUM_AMOUNT_OF_DELEGATES; count++)
  {
    delegates[count].public_address = (char*)calloc(XCASH_WALLET_LENGTH+1,sizeof(char));
    delegates[count].total_vote_count = (char*)calloc(100,sizeof(char));
    delegates[count].IP_address = (char*)calloc(256,sizeof(char));
    delegates[count].delegate_name = (char*)calloc(MAXIMUM_BUFFER_SIZE_DELEGATES_NAME+1,sizeof(char));
    delegates[count].about = (char*)calloc(1025,sizeof(char));
    delegates[count].website = (char*)calloc(256,sizeof(char));
    delegates[count].team = (char*)calloc(256,sizeof(char));
    delegates[count].pool_mode = (char*)calloc(10,sizeof(char));
    delegates[count].fee_structure = (char*)calloc(11,sizeof(char));
    delegates[count].server_settings = (char*)calloc(1025,sizeof(char));
    delegates[count].block_verifier_score = (char*)calloc(10,sizeof(char));
    delegates[count].online_status = (char*)calloc(10,sizeof(char));
    delegates[count].block_verifier_total_rounds = (char*)calloc(10,sizeof(char));
    delegates[count].block_verifier_online_total_rounds = (char*)calloc(10,sizeof(char));
    delegates[count].block_verifier_online_percentage = (char*)calloc(10,sizeof(char));
    delegates[count].block_producer_total_rounds = (char*)calloc(10,sizeof(char));
    delegates[count].block_producer_block_heights = (char*)calloc(50000,sizeof(char));
    delegates[count].public_key = (char*)calloc(VRF_PUBLIC_KEY_LENGTH+1,sizeof(char));
    if (delegates[count].public_address == NULL || delegates[count].total_vote_count == NULL || delegates[count].IP_address == NULL || delegates[count].delegate_name == NULL || delegates[count].about == NULL || delegates[count].website == NULL || delegates[count].team == NULL || delegates[count].pool_mode == NULL || delegates[count].fee_structure == NULL || delegates[count].server_settings == NULL || delegates[count].block_verifier_score == NULL || delegates[count].online_status == NULL || delegates[count].block_verifier_total_rounds == NULL || delegates[count].block_verifier_online_total_rounds == NULL || delegates[count].block_verifier_online_percentage == NULL || delegates[count].block_producer_total_rounds == NULL || delegates[count].block_producer_block_heights == NULL || delegates[count].public_key == NULL)
    {
      color_print("Could not allocate the memory needed on the heap","red");
      exit(0);
    }
  }

  memcpy(delegates[0].public_address,"XCA1h3yJ318hJGTFeXfYyEcyE7G4hX7jrCbvz21VecJGhf64Tw51yWii2Q1e76fJbB26Ea8CRipmdW6ZHQcRrLKx3cxRkr5M12",XCASH_WALLET_LENGTH);
  memcpy(delegates[0].total_vote_count,"0",1);
  memcpy(delegates[0].IP_address,"delegates.xcash.foundation",26);
  memcpy(delegates[0].delegate_name,"delegates_xcash_foundation",26);
  memcpy(delegates[0].about,"Official X-Network node",23);
  memcpy(delegates[0].website,"delegates.xcash.foundation",26);
  memcpy(delegates[0].team,"X-Network Team",14);
  memcpy(delegates[0].pool_mode,"false",5);
  memcpy(delegates[0].fee_structure,"0",1);
  memcpy(delegates[0].server_settings,"Operating System = Ubuntu 18.04 CPU = 32 threads (Intel 2xE5 - 2660 - 2.2GHz RAM = 256GB DDR3 Hard drive = 2x240 GB SSD + 4x2TB SATA Bandwidth Transfer = Unlimited Bandwidth Speed = 500 Mbps upload and 500 Mbps download",219);
  memcpy(delegates[0].block_verifier_score,"0",1);
  memcpy(delegates[0].online_status,"true",4);
  memcpy(delegates[0].block_verifier_total_rounds,"0",1);
  memcpy(delegates[0].block_verifier_online_total_rounds,"0",1);
  memcpy(delegates[0].block_verifier_online_percentage,"0",1);
  memcpy(delegates[0].block_producer_total_rounds,"0",1);
  memcpy(delegates[0].block_producer_block_heights,"0",1);
  memcpy(delegates[0].public_key,"ad98cadb3b13229c78709876955247cbef40d5b15c4842be605b0e8b30c97a7a",VRF_PUBLIC_KEY_LENGTH);

  memcpy(delegates[1].public_address,"XCA1kkdrRQ9SC7wfJ3F329giei31r13wKEKiD1ZMYf6nBiU8KE6a6LDJTZobfJ58o8A3vtGrAkzfHDd815kac7F17iPhK9zYGG",XCASH_WALLET_LENGTH);
  memcpy(delegates[1].total_vote_count,"0",1);
  memcpy(delegates[1].IP_address,"officialdelegate.xcash.foundation",33);
  memcpy(delegates[1].delegate_name,"officialdelegate_xcash_foundation",33);
  memcpy(delegates[1].about,"Official X-Network Shared Delegate",34);
  memcpy(delegates[1].website,"officialdelegate.xcash.foundation",33);
  memcpy(delegates[1].team,"X-Network Team",14);
  memcpy(delegates[1].pool_mode,"true",4);
  memcpy(delegates[1].fee_structure,"0",1);
  memcpy(delegates[1].server_settings,"Operating System = Ubuntu 18.04 CPU = 8 threads (Intel E3-1246 v3 - 3.50GHz RAM = 32GB DDR3 Hard drive = 2x HDD SATA 2 TB Bandwidth Transfer = Unlimited Bandwidth Speed = 1 Gbps upload and 1 Gbps download",204);
  memcpy(delegates[1].block_verifier_score,"0",1);
  memcpy(delegates[1].online_status,"true",4);
  memcpy(delegates[1].block_verifier_total_rounds,"0",1);
  memcpy(delegates[1].block_verifier_online_total_rounds,"0",1);
  memcpy(delegates[1].block_verifier_online_percentage,"0",1);
  memcpy(delegates[1].block_producer_total_rounds,"0",1);
  memcpy(delegates[1].block_producer_block_heights,"0",1);
  memcpy(delegates[1].public_key,"ad98cadb3b13229c78709876955247cbef40d5b15c4842be605b0e8b30c97a7a",VRF_PUBLIC_KEY_LENGTH);

  // initialize the votes struct 
  for (count = 0; count < MAXIMUM_AMOUNT_OF_DELEGATES; count++)
  {
    votes[count].public_address_created_reserve_proof = (char*)calloc(XCASH_WALLET_LENGTH+1,sizeof(char));
    votes[count].public_address_voted_for = (char*)calloc(XCASH_WALLET_LENGTH+1,sizeof(char));
    votes[count].total = (char*)calloc(100,sizeof(char));
    votes[count].reserve_proof = (char*)calloc(BUFFER_SIZE_RESERVE_PROOF+1,sizeof(char));
    if (votes[count].public_address_created_reserve_proof == NULL || votes[count].public_address_voted_for == NULL || votes[count].total == NULL || votes[count].reserve_proof == NULL)
    {
      color_print("Could not allocate the memory needed on the heap","red");
      exit(0);
    }
  }

  memcpy(votes[0].public_address_created_reserve_proof,CHECK_RESERVE_PROOF_TEST_PUBLIC_ADDRESS,sizeof(CHECK_RESERVE_PROOF_TEST_PUBLIC_ADDRESS)-1);
  memcpy(votes[0].public_address_voted_for,CHECK_RESERVE_PROOF_TEST_PUBLIC_ADDRESS,sizeof(CHECK_RESERVE_PROOF_TEST_PUBLIC_ADDRESS)-1);
  memcpy(votes[0].total,"0",1);
  memcpy(votes[0].reserve_proof,CHECK_RESERVE_PROOF_TEST_RESERVE_PROOF,sizeof(CHECK_RESERVE_PROOF_TEST_RESERVE_PROOF)-1);

  memcpy(votes[1].public_address_created_reserve_proof,CHECK_RESERVE_PROOF_TEST_PUBLIC_ADDRESS,sizeof(CHECK_RESERVE_PROOF_TEST_PUBLIC_ADDRESS)-1);
  memcpy(votes[1].public_address_voted_for,CHECK_RESERVE_PROOF_TEST_PUBLIC_ADDRESS,sizeof(CHECK_RESERVE_PROOF_TEST_PUBLIC_ADDRESS)-1);
  memcpy(votes[1].total,"0",1);
  memcpy(votes[1].reserve_proof,CHECK_RESERVE_PROOF_TEST_RESERVE_PROOF,sizeof(CHECK_RESERVE_PROOF_TEST_RESERVE_PROOF)-1);
 
  // write the start test message
  color_print(TEST_OUTLINE,"blue");
  fprintf(stderr,"\033[1;34mstring functions test - Total test: %d\033[0m\n",STRING_FUNCTIONS_TOTAL_TEST);
  color_print(TEST_OUTLINE,"blue");
  fprintf(stderr,"\n");
 
  // run the test
 
  // test parse_json_data
  memcpy(result_test,MESSAGE,sizeof(MESSAGE)-1);
  if (parse_json_data(result_test,"message_settings_1",data_test,sizeof(data_test)) == 1 && strncmp(data_test,"XCASH_DPOPS_TEST_DATA_1",sizeof(data_test)) == 0)
  {
    memset(data_test,0,sizeof(data_test));
    if (parse_json_data(result_test,"message_settings_2",data_test,sizeof(data_test)) == 1 && strncmp(data_test,"XCASH_DPOPS_TEST_DATA_2",sizeof(data_test)) == 0)
    {
      color_print("PASSED! Test for parse_json_data","green");
      count_test++;
    }
    else
    {
      color_print("FAILED! Test for parse_json_data","red");
    }
  }
  else
  {
    color_print("FAILED! Test for parse_json_data","red");
  }

  // test for random_string
  memset(result_test,0,sizeof(result_test));
  if (random_string(result_test,RANDOM_STRING_LENGTH) == 1)
  {   
    color_print("PASSED! Test for random_string","green");
    count_test++;
  }
  else
  {
    color_print("FAILED! Test for random_string","red");
  }

  // test create_json_data_from_database_document_array
  memset(result_test,0,sizeof(result_test));
  if (create_json_data_from_database_document_array(&database_data,result_test,"") == 1 && strncmp(result_test,CREATE_JSON_DATA_FROM_DATABASE_DOCUMENT_ARRAY_TEST_DATA,BUFFER_SIZE) == 0)
  {
    color_print("PASSED! Test for create_json_data_from_database_document_array","green");
    count_test++;
  }
  else
  {
    color_print("FAILED! Test for create_json_data_from_database_document_array","red");
  }

  // test create_json_data_from_database_multiple_documents_array
  memset(result_test,0,sizeof(result_test));
  if (create_json_data_from_database_multiple_documents_array(&database_multiple_documents_fields,result_test,"") == 1 && strncmp(result_test,CREATE_JSON_DATA_FROM_DATABASE_MULTIPLE_DOCUMENTS_ARRAY_TEST_DATA,BUFFER_SIZE) == 0)
  {
    color_print("PASSED! Test for create_json_data_from_database_multiple_documents_array","green");
    count_test++;
  }
  else
  {
    color_print("FAILED! Test for create_json_data_from_database_multiple_documents_array","red");
  }

  // test create_json_data_from_delegates_array
  memset(result_test,0,sizeof(result_test));
  if (create_json_data_from_delegates_array(delegates,result_test,"") == 1 && strncmp(result_test,CREATE_JSON_DATA_FROM_DELEGATES_ARRAY_TEST_DATA,BUFFER_SIZE) == 0)
  {
    color_print("PASSED! Test for create_json_data_from_database_multiple_documents_array","green");
    count_test++;
  }
  else
  {
    color_print("FAILED! Test for create_json_data_from_database_multiple_documents_array","red");
  }

  // test create_json_data_from_votes_array
  memset(result_test,0,sizeof(result_test));
  if (create_json_data_from_votes_array(votes,result_test,"") == 1 && strncmp(result_test,CREATE_JSON_DATA_FROM_VOTES_ARRAY_TEST_DATA,BUFFER_SIZE) == 0)
  {
    color_print("PASSED! Test for create_json_data_from_database_multiple_documents_array","green");
    count_test++;
  }
  else
  {
    color_print("FAILED! Test for create_json_data_from_database_multiple_documents_array","red");
  }

  // test for parse_reserve_bytes_data
  memset(result_test,0,sizeof(result_test));
  if (parse_reserve_bytes_data(result_test,NETWORK_BLOCK,8) == 1 && memcmp(result_test,"d65cd4647f61953d6fa26fd80d1646ec96822abb5d3a87bcf84fc33daf32c0754932b5ec9abcbda86a053ce11508c08281a2fa386ed87edbd442d71934a6450d",VRF_BETA_LENGTH) == 0)
  {
    color_print("PASSED! Test for parse_reserve_bytes_data","green");
    count_test++;
  }
  else
  {
    color_print("FAILED! Test for parse_reserve_bytes_data","red");
  }

  // test for counting occurences of a substring in a string
  memset(result_test,0,sizeof(result_test));
  memcpy(result_test,TEST_OUTLINE,sizeof(TEST_OUTLINE)-1);
  if (string_count(result_test,"-") == strnlen(TEST_OUTLINE,BUFFER_SIZE) && string_count(result_test,"--") == strnlen(TEST_OUTLINE,BUFFER_SIZE)/2)  
  {
    color_print("PASSED! Test for string_count","green");
    count_test++;
  }
  else
  {
    color_print("FAILED! Test for string_count","red");
  }

  // test for string replace
  memset(result_test,0,sizeof(result_test));
  memcpy(result_test,"{\r\n \"message_settings\": \"string_replace_test\",\r\n}",49);
  if (string_replace(result_test,BUFFER_SIZE,"string_replace_test","string_replace") == 1 && strncmp(result_test,"{\r\n \"message_settings\": \"string_replace\",\r\n}",BUFFER_SIZE) == 0)
  {
    memset(result_test,0,sizeof(result_test));
    memcpy(result_test,"{\r\n \"message_settings\": \"string_replace_test\",\r\n}",49);
     if (string_replace(result_test,BUFFER_SIZE,"\"","\\\"") == 1 && strncmp(result_test,"{\r\n \\\"message_settings\\\": \\\"string_replace_test\\\",\r\n}",BUFFER_SIZE) == 0)
     {
       memset(result_test,0,sizeof(result_test));
       memcpy(result_test,"{\r\n \"message_settings\": \"string_replace_test\",\r\n}",49);
       if (string_replace(result_test,BUFFER_SIZE,"_test","") == 1 && strncmp(result_test,"{\r\n \"message_settings\": \"string_replace\",\r\n}",BUFFER_SIZE) == 0)
       {
         memset(result_test,0,sizeof(result_test));
         memcpy(result_test,"{\r\n \"message_settings\": \"string_replace\",\r\n}",44);
         if (string_replace(result_test,BUFFER_SIZE,"string_replace_test","") == 0 && strncmp(result_test,"{\r\n \"message_settings\": \"string_replace\",\r\n}",BUFFER_SIZE) == 0)
         {    
           color_print("PASSED! Test for string_replace","green");
           count_test++;
         }
         else
         {
           color_print("FAILED! Test for string_replace","red");
         }
       }
       else
       {
         color_print("FAILED! Test for string_replace","red");
       }
     }
     else
     {
       color_print("FAILED! Test for string_replace","red");
     }
  }
  else
  {
    color_print("FAILED! Test for string_replace","red");
  }

  // reset the database_data struct
  for (count = 0; count < DATABASE_DATA; count++)
  {
    pointer_reset(database_data.item[count]);
    pointer_reset(database_data.value[count]);
  }

  // reset the database_multiple_documents_fields struct
  for (count = 0; count < 2; count++)
  {
    for (counter = 0; counter < DATABASE_DATA; counter++)
    {
      pointer_reset(database_multiple_documents_fields.item[count][counter]);
      pointer_reset(database_multiple_documents_fields.value[count][counter]);
    }
  }

  // reset the delegates struct
  for (count = 0; (int)count < MAXIMUM_AMOUNT_OF_DELEGATES; count++)
  {
    pointer_reset(delegates[count].public_address);
    pointer_reset(delegates[count].total_vote_count);
    pointer_reset(delegates[count].IP_address);
    pointer_reset(delegates[count].delegate_name);
    pointer_reset(delegates[count].about);
    pointer_reset(delegates[count].website);
    pointer_reset(delegates[count].team);
    pointer_reset(delegates[count].pool_mode);
    pointer_reset(delegates[count].fee_structure);
    pointer_reset(delegates[count].server_settings);
    pointer_reset(delegates[count].block_verifier_score);
    pointer_reset(delegates[count].online_status);
    pointer_reset(delegates[count].block_verifier_total_rounds);
    pointer_reset(delegates[count].block_verifier_online_total_rounds);
    pointer_reset(delegates[count].block_verifier_online_percentage);
    pointer_reset(delegates[count].block_producer_total_rounds);
    pointer_reset(delegates[count].block_producer_block_heights);
    pointer_reset(delegates[count].public_key);
  }

  // reset the votes struct
  for (count = 0; count < MAXIMUM_AMOUNT_OF_DELEGATES; count++)
  {
    pointer_reset(votes[count].public_address_created_reserve_proof);
    pointer_reset(votes[count].public_address_voted_for);
    pointer_reset(votes[count].total);
    pointer_reset(votes[count].reserve_proof);
  }
 
  // write the end test message
  if (count_test == STRING_FUNCTIONS_TOTAL_TEST)
  {
    fprintf(stderr,"\n\n");
    color_print(TEST_OUTLINE,"green");
    fprintf(stderr,"\033[1;32mstring functions test - Passed test: %d, Failed test: 0\033[0m\n",STRING_FUNCTIONS_TOTAL_TEST);
    color_print(TEST_OUTLINE,"green");
    fprintf(stderr,"\n\n");
  }
  else
  {
    fprintf(stderr,"\n\n");
    color_print(TEST_OUTLINE,"red");
    fprintf(stderr,"\033[1;31mstring functions test - Passed test: %d, Failed test: %d\033[0m\n",count_test,STRING_FUNCTIONS_TOTAL_TEST-count_test);
    color_print(TEST_OUTLINE,"red");
    fprintf(stderr,"\n\n");
  }
  return count_test;

  #undef STRING_FUNCTIONS_TOTAL_TEST
  #undef DATABASE_DATA
  #undef MESSAGE
  #undef DATA1
  #undef DATA2
}