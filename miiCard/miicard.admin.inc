<?php

function miicard_admin_settings() {
  $form = array();

  $form['miicard_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('miiCard Consumer Key'),
    '#default_value' => variable_get('miicard_consumer_key', ''),
    '#required' => true,
  );

  $form['miicard_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('miiCard Consumer Secret'),
    '#default_value' => variable_get('miicard_consumer_secret', ''),
    '#required' => true,
  );

  $form['miicard_oauth'] = array(
    '#type' => 'textfield',
    '#title' => t('miiCard OAuth Endpoint'),
    '#default_value' => variable_get('miicard_oauth', MIICARD_OAUTH),
    '#required' => true,
  );

  $form['miicard_api'] = array(
    '#type' => 'textfield',
    '#title' => t('miiCard API Endpoint'),
    '#default_value' => variable_get('miicard_api', MIICARD_API),
    '#required' => true,
  );

  $form['miicard_add_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Add miiCard link text'),
    '#default_value' => variable_get('miicard_add_link', MIICARD_ADD_LINK),
    '#required' => true,
  );

  $form['miicard_sign_in_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Sign in with miiCard link text'),
    '#default_value' => variable_get('miicard_sign_in_link', MIICARD_SIGN_IN_LINK),
    '#required' => true,
  );

  $form['miicard_remove_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Sign in with miiCard link text'),
    '#default_value' => variable_get('miicard_remove_link', MIICARD_REMOVE_LINK),
    '#required' => true,
  );

  $period = array(
    0 => t('Never'),
    21600 => t('6 hours'),
    43200 => t('12 hours'),
    86400 => t('24 hours'),
    172800 => t('2 days'),
    604800 => t('1 week'),
  );
  
  $form['miicard_refresh_period'] = array(
    '#type' => 'select',
    '#title' => t('Refresh period'),
    '#description' => t("Refresh users' miiCards on cron"),
    '#options' => $period,
    '#default_value' => variable_get('miicard_refresh_period', 0),
  );
    
  return system_settings_form($form);
}

