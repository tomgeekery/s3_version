<?php

/**
 * @file
 * Administration form for s3 version viewer settings.
 */

/**
 * Admin form for s3_version settings.
 */
function s3_version_admin_settings() {
  
  $client = s3_version_aws_client();
  
  $options = array();
  
  // Grab all buckets.
  $buckets = $client->listBuckets();
  
  // Loop through each bucket to build select list.
  foreach ($buckets['Buckets'] as $bucket_key => $bucket_value) {
    $options[$bucket_value['Name']] = $bucket_value['Name'];
  }
  
  $form['s3_version_bucket'] = array(
    '#type' => 'select',
    '#title' => t('S3 Bucket'),
    '#options' => $options,
    '#default_value' => variable_get('s3_version_bucket', ''),
  );
  
  // Check to see if bucket has versioning enabled.
  if (variable_get('s3_version_bucket')) {
    $version_status = $client->getBucketVersioning(array(
      'Bucket' => variable_get('s3_version_bucket'),
    ));
    if ($version_status['Status'] != 'Enabled') {
      $form['s3_version_bucket_status'] = array(
        '#markup' => 'Bucket does not have versioning enabled. Click ' . 
        l('here', 'admin/config/media/s3_viewer/admin/' .
        urlencode(variable_get('s3_version_bucket')) . 
        '/version_enable') . 
        ' to enable.',
      );
    }
  }
  
  return system_settings_form($form);
}
