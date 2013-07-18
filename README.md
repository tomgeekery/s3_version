s3_version
==========

Drupal 7 module for viewing and restoring versioned files stored on AWS S3.

CAUTION! Do not use this module with production sites/AWS buckets. It is very alpha and not thoroughly tested.

With that said this module also relies on a sandbox Drupal 7 module found here:
https://drupal.org/sandbox/tobiasb/1865566

This module requires libraries 2.0+, awssdk (from sandbox), and the AWS SDK for PHP (tested w/2.1.2).

The SDK should be built with composer and can be downloaded from here:
https://github.com/aws/aws-sdk-php/tree/2.1.2

As of now you can browse files in your S3 buckets, enable versioning on a bucket, view versions of individual files,
and restore versions of files. 
