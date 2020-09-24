#!/bin/bash
echo Provisioning CloudFormation Stack!
docker run --rm -i -v ~/.aws:/root/.aws  -v ~/git/tt304_unicamp:/root/tt_304_unicamp amazon/aws-cli cloudformation create-stack --stack-name tt304Unicamp --template-body file:///root/tt_304_unicamp/infraestrutura/cloudformation.yaml