import datetime
import hashlib
import json 
from flask import Flask, jsonify


class Blockchain:
    def __init__(self,difficulty=4):
        self.chain = []
        self.difficulty = difficulty
        self.create_block(proof=1, previous_hash='0')

    def create_block(self, proof, previous_hash):
        block = {
            'index': len(self.chain) + 1,
            'timestamp': str(datetime.datetime.now()),
            'proof': proof,
            'previous_hash': previous_hash,
        }
        self.chain.append(block)
        return block

    def get_previous_block(self):
        return self.chain[-1]

    def proof_of_work(self, previous_proof):
        new_proof = 1
        valid_proof = False

        while not valid_proof:
            hash_operation = hashlib.sha256(str(new_proof + previous_proof).encode()).hexdigest()
            if hash_operation[:5] == '00000':
                valid_proof = True
            else:
                new_proof += 1

        return new_proof

    def hash(self, block):
        encoded_block = json.dumps(block, sort_keys=True).encode()
        return hashlib.sha256(encoded_block).hexdigest()

    def chain_valid(self, chain):
        previous_block = chain[0]
        block_index = 1

        while block_index < len(chain):
            block = chain[block_index]
            
            # 1. Verify previous_hash match
            if block['previous_hash'] != self.hash(previous_block):
                return False

            # 2. Verify proof of work math
            previous_proof = previous_block['proof']
            proof = block['proof']
            hash_operation = hashlib.sha256(str(proof + previous_proof).encode()).hexdigest()

            if hash_operation[:5] != '00000':
                return False

            previous_block = block
            block_index += 1

        return True


app = Flask(__name__)
blockchain = Blockchain()

@app.route('/mine_block', methods=['GET'])
def mine_block():
    previous_block = blockchain.get_previous_block()
    previous_proof = previous_block['proof']
    proof = blockchain.proof_of_work(previous_proof)
    previous_hash = blockchain.hash(previous_block)
    block = blockchain.create_block(proof, previous_hash)

    response = {
        'message': 'A block is MINED',
        'index': block['index'],
        'timestamp': block['timestamp'],
        'proof': block['proof'],
        'previous_hash': block['previous_hash']
    }
    return jsonify(response), 200


@app.route('/get_chain', methods=['GET'])
def display_chain():
    response = {
        'chain': blockchain.chain,
        'length': len(blockchain.chain)
    }
    return jsonify(response), 200


@app.route('/valid', methods=['GET'])
def valid():
    is_valid = blockchain.chain_valid(blockchain.chain)
    if is_valid:
        response = {'message': 'The Blockchain is valid.'}
    else:
        response = {'message': 'The Blockchain is not valid.'}
    return jsonify(response), 200


if __name__ == '__main__':
    app.run(host='127.0.0.1', port=5000)