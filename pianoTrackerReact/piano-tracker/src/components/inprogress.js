import React from 'react';
import '../App.css';
import {
    Table,
  } from 'semantic-ui-react'

const InProgress = (props) => {

    return (
        <div>
            <h2 style={{color: 'dimgrey'}}>in progress</h2>
            <Table>
            <Table.Header>
                <Table.Row>
                <Table.HeaderCell>Name</Table.HeaderCell>
                <Table.HeaderCell>Premium Plan</Table.HeaderCell>
                </Table.Row>
            </Table.Header>
            <Table.Body>
                <Table.Row>
                <Table.Cell>John</Table.Cell>
                <Table.Cell>No</Table.Cell>
                </Table.Row>
                <Table.Row>
                <Table.Cell>Jamie</Table.Cell>
                <Table.Cell>Yes</Table.Cell>
                </Table.Row>
                <Table.Row>
                <Table.Cell>Jill</Table.Cell>
                <Table.Cell>Yes</Table.Cell>
                </Table.Row>
            </Table.Body>
            </Table>
      </div>
    )
}

export default InProgress
