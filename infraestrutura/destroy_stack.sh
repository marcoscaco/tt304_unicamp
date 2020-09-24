#!/bin/bash
echo Desprovisioning CloudFormation Stack!
docker run --rm -i -v ~/.aws:/root/.aws  -v ~/git/tt304_unicamp:/root/tt_304_unicamp amazon/aws-cli cloudformation delete-stack --stack-name tt304Unicamp